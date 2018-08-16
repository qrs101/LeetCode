package main

type Interval struct {
   Start int
   End   int
}

func insert(intervals []Interval, newInterval Interval) []Interval {
	res := make([]Interval, 0)
	var i int
	for i = 0; i < len(intervals); i++ {
		if newInterval.Start <= intervals[i].End {
			if newInterval.Start > intervals[i].Start {
				newInterval.Start = intervals[i].Start
			}
			break
		}
	}
	res = append(res, intervals[0 : i]...)
	for i = len(intervals) - 1; i >= 0; i-- {
		if newInterval.End >= intervals[i].Start {
			if newInterval.End < intervals[i].End {
				newInterval.End = intervals[i].End
			}
			break
		}
	}
	res = append(res, newInterval)
	res = append(res, intervals[i + 1:]...)
	return res
}