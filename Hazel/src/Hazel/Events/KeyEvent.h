#pragma once

#include "Event.h"
#include <sstream>

namespace Hazel {

	class HAZEL_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }


		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;

	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode),m_RepratCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepratCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode<<"("<< m_RepratCount<<"repeats)";

			return ss.str();
		}

		//static EventType GetStaticType() { return EventType::KeyPressed; }
		//virtual EventType GetEventType() const override { return GetStaticType(); }
		//virtual const char* GetName() const override { return "KeyPressed"; }
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepratCount;
	};


	class HAZEL_API KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;

			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}