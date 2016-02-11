#include "TrialVector.h"

void TrialVector::AddElement( int i )
{
	StringList::iterator iter;
	switch (type)
	{
		case FRONT_FRONT : 
			tVector.push_back(strings[i]);
			break;
		case FRONT_REAR : 
			tVector.push_back(strings[i]);
			break;
		case REAR_FRONT : 
			iter = tVector.end();
			tVector.insert(iter, strings[i]);
			break;
		case REAR_REAR:
			iter = tVector.end();
			tVector.insert(iter, strings[i]);
	        break;
	    default:
		    break;
	}
}

void TrialVector::RemoveElement() 
{
	StringList::iterator iter;
	switch (type)
	{
		case FRONT_FRONT : 
			tVector.pop_back();
			break;
		case FRONT_REAR : 
			iter = tVector.end()--;
			tVector.erase(iter);
			break;
		case REAR_FRONT : 
			iter = tVector.begin();
			tVector.pop_back();
			break;
		case REAR_REAR:
			iter = tVector.end();
			tVector.erase(iter);
	        break;
	default:
		break;
	}
}

void TrialVector::Clear()
{
	tVector.~vector();
}
