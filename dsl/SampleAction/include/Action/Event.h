#ifndef EVENT_H_
#define EVENT_H_
typedef  int EventId;
class Event
{
public:
	Event(EventId eventId):eventId(eventId){

	}
	EventId getEventId()const{
		return eventId;
	}
private:
	EventId eventId;
};
#endif
