#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };



bool mycomp(Interval a, Interval b) {
	return a.start > b.start;
}

bool mycomp_s(Interval a, Interval b) {
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> res;
	sort (intervals.begin(), intervals.end(), mycomp);
	int index =0 ;
	for (int i=0; i < intervals.size(); i++ ) {
		if (index != 0 && intervals[index - 1].start <= intervals[i].end) {
			intervals[index - 1].end = max(intervals[index-1].end, intervals[i].end);
			intervals[index - 1].start = min(intervals[index-1].start, intervals[i].start);
		}
		else {
			intervals[index] = intervals[i];
			index++;
			//cout <<index;
		
		}
	}
	for (int i=0; i < intervals.size(); i++ )
		cout <<  intervals[i].start<<  " " << intervals[i].end <<endl;
	cout << "new";
	/*for (int i=0; i<index; i++)
		res[i] = intervals[i];
	for (int i=0; i < res.size(); i++ )
		cout <<  res[i].start<<  " " << res[i].end <<endl;*/
	intervals.resize(index);
	sort (intervals.begin(), intervals.end(), mycomp_s);
	return intervals;

}
//Works
static bool comp(const Interval& a, const Interval& b){
    return a.start < b.start;
}
vector<Interval> merge1(vector<Interval> &intervals) {
    vector<Interval> result;
    if(intervals.empty()){
        return result;
    }
    sort(intervals.begin(), intervals.end(), comp);
    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start <= result.back().end){
            Interval temp(result.back().start, max(result.back().end, intervals[i].end));
            result.pop_back();
            result.push_back(temp);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}


int main() {
	vector<Interval> intervals;
	vector<Interval> res;
	intervals.push_back( Interval(1,10));
	intervals.push_back( Interval(3,4));
	intervals.push_back( Interval(5,7));
	intervals.push_back( Interval(6,8));
	res = merge1(intervals);
	for (int i=0; i < res.size(); i++ )
		cout <<  res[i].start<<  " " << res[i].end <<endl;

	return 0;
}