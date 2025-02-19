////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DragAdornerBehavior.h"

#include <NsCore/ReflectionImplement.h>
#include <NsCore/Delegate.h>
#include <NsGui/DragDrop.h>
#include <NsGui/UIElementData.h>
#include <NsGui/PropertyMetadata.h>
#include <NsDrawing/Point.h>


using namespace Inventory;
using namespace Noesis;


////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::Point& DragAdornerBehavior::GetDragStartOffset() const
{
    return GetValue<Noesis::Point>(DragStartOffsetProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehavior::SetDragStartOffset(const Noesis::Point& offset)
{
    SetValue<Noesis::Point>(DragStartOffsetProperty, offset);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float DragAdornerBehavior::GetDraggedItemX() const
{
    return GetValue<float>(DraggedItemXProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehavior::SetDraggedItemX(float x)
{
    SetReadOnlyProperty<float>(DraggedItemXProperty, x);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
float DragAdornerBehavior::GetDraggedItemY() const
{
    return GetValue<float>(DraggedItemYProperty);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehavior::SetDraggedItemY(float y)
{
    SetReadOnlyProperty<float>(DraggedItemYProperty, y);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
Noesis::Ptr<Freezable> DragAdornerBehavior::CreateInstanceCore() const
{
    return *new DragAdornerBehavior();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehavior::OnAttached()
{
    ParentClass::OnAttached();

    FrameworkElement* element = GetAssociatedObject();
    element->SetAllowDrop(true);
    element->DragOver() += MakeDelegate(this, &DragAdornerBehavior::OnDragOver);
    element->Drop() += MakeDelegate(this, &DragAdornerBehavior::OnDrop);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehavior::OnDetaching()
{
    FrameworkElement* element = GetAssociatedObject();
    element->ClearLocalValue(UIElement::AllowDropProperty);
    element->DragOver() -= MakeDelegate(this, &DragAdornerBehavior::OnDragOver);
    element->Drop() -= MakeDelegate(this, &DragAdornerBehavior::OnDrop);

    ParentClass::OnDetaching();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehavior::OnDragOver(BaseComponent*, const DragEventArgs& e)
{
    Noesis::Point position = e.GetPosition(GetAssociatedObject());
    Noesis::Point offset = GetDragStartOffset();
    SetDraggedItemX(position.x - offset.x);
    SetDraggedItemY(position.y - offset.y);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void DragAdornerBehavior::OnDrop(BaseComponent*, const DragEventArgs& e)
{
    e.effects = DragDropEffects_None;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
NS_BEGIN_COLD_REGION

NS_IMPLEMENT_REFLECTION(DragAdornerBehavior, "Inventory.DragAdornerBehavior")
{
    UIElementData* data = NsMeta<UIElementData>(TypeOf<SelfClass>());
    data->RegisterProperty<Noesis::Point>(DragStartOffsetProperty, "DragStartOffset",
        PropertyMetadata::Create(Noesis::Point(0.0f, 0.0f)));
    data->RegisterPropertyRO<float>(DraggedItemXProperty, "DraggedItemX",
        PropertyMetadata::Create(0.0f));
    data->RegisterPropertyRO<float>(DraggedItemYProperty, "DraggedItemY",
        PropertyMetadata::Create(0.0f));
}

NS_END_COLD_REGION

////////////////////////////////////////////////////////////////////////////////////////////////////
const Noesis::DependencyProperty* DragAdornerBehavior::DragStartOffsetProperty;
const Noesis::DependencyProperty* DragAdornerBehavior::DraggedItemXProperty;
const Noesis::DependencyProperty* DragAdornerBehavior::DraggedItemYProperty;
