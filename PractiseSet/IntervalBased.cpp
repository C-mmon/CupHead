struct Interval 
{
	 int start;
	 int end;
};

//Global meeting timing
vector <Interval> meetingTime;
bool CanAttentMeeting()
{
 //sort the meeting by start time
 sort(meetingTime.begin(), meetingTime.end(), [](const Interval&a, const Interval &b)
 {
	if(a.start != b.start)
	{ return a.start < b.start; }
	return a.end < b.end; //tie break. select the one which is ending early
	}
	
	for(int i=0; i<meetingTime.size()-1;i++)
	{
	 if(meetingTime[i].end <= meetingTime[i+1].start)
	 {
	   continue;
	  }
	  else 
	  {
	   return false;
	  }
	 }
	 return true;
}
