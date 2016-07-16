#include "ModeSelectorMenu.h"
#include "TouchRectangle.h"
#include "TouchImage.h"

namespace touchpoints { namespace ui {
	ModeSelectorMenu::ModeSelectorMenu() {}

	ModeSelectorMenu::ModeSelectorMenu(vec2 startPoint, string filePath, bool visible,
		function<void(vec2 point, Menu *self)> touchEventHandler) : ModeSelectorMenu(startPoint, filePath,
		visible, multimap<int, shared_ptr<drawing::TouchShape>>(), multimap<int, shared_ptr<Menu>>(), touchEventHandler) {}

	ModeSelectorMenu::ModeSelectorMenu(vec2 startPoint, string filePath, bool visible,
		multimap<int, shared_ptr<drawing::TouchShape>> composingShapes,
		function<void(vec2 point, Menu *self)> touchEventHandler) 
		: ModeSelectorMenu(startPoint, filePath, visible, composingShapes,
			multimap<int, shared_ptr<Menu>>(), touchEventHandler) {}

	ModeSelectorMenu::ModeSelectorMenu(vec2 startPoint, string filePath, bool visible,
		multimap<int, shared_ptr<Menu>> composingMenus, 
		function<void(vec2 point, Menu *self)> touchEventHandler) 
		: ModeSelectorMenu(startPoint, filePath, visible,
		multimap<int, shared_ptr<drawing::TouchShape>>(), composingMenus, touchEventHandler) {}

	ModeSelectorMenu::ModeSelectorMenu(vec2 startPoint, string filePath, bool visible,
		multimap<int, shared_ptr<drawing::TouchShape>> composingShapes,
		multimap<int, shared_ptr<Menu>> composingMenus, 
		function<void(vec2 point, Menu *self)> touchEventHandler) 
		: Menu(startPoint, defaultWidth, defaultHeight, visible, composingShapes, composingMenus, touchEventHandler),
		filePath(filePath)
	{
		populateShapes();
	}

	void ModeSelectorMenu::populateShapes()
	{
		auto startX = startPoint.x;
		auto startY = startPoint.y;
		auto endX = startX + width;
		auto endY = startY + height;
		auto imageStart = vec2(startX + Menu::defaultImageOffsetX, startY + Menu::defaultImageOffsetY);

		AddShape(0, shared_ptr<drawing::TouchRectangle>(new drawing::TouchRectangle(startX, startY, endX, endY, purple, 0, true)));
		AddShape(1, shared_ptr<drawing::TouchRectangle>(new drawing::TouchRectangle(startX, startY, endX, endY, grey, defaultBorderThickness, false)));
		if(filePath != "")
		{
			AddShape(2, shared_ptr<drawing::TouchImage>(new drawing::TouchImage(imageStart, Menu::defaultImageWidth, Menu::defaultImageHeight, filePath)));
		}
	}
}}