#pragma once


#include "Event.h"
#include <sstream>

namespace Hazel {
	
	class HAZEL_API MouseMoveEvent : public Event {

	public:
		MouseMoveEvent(float x, float y)
			: m_Mousex(x), m_Mousey(y) {}


		inline float GetX() const { return m_Mousex; }
		inline float GetY() const { return m_Mousey; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent:" << m_Mousex << "," << m_Mousey;
			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_Mousex, m_Mousey;
	};

	class HAZEL_API MouseScrolledEvent : public Event {

	public:
		MouseScrolledEvent(float xOffset, float yOffSet)
			: m_XOffset(xOffset), m_YOffset(yOffSet) {}
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffSet() const { return m_YOffset; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent:" << GetXOffset() << "," << GetYOffSet();
			return ss.str();

		}

		EVENT_CLASS_TYPE(MouseScrolled)

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;

	};

	class HAZEL_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		int m_Button;
	};


	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent {
	
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent:" << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent:" << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}