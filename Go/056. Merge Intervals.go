package main

import "sort"

type Interval struct {
   Start int
   End   int
}

type IntervalSort []Interval

func (is IntervalSort)Len() int {
	return len(is)
}

func (is IntervalSort)Swap(i, j int) {
	is[i], is[j] = is[j], is[i]
}

func (is IntervalSort)Less(i, j int) bool {
	return is[i].Start < is[j].Start
}

func merge(intervals []Interval) []Interval {
	res := make([]Interval, 0)
	if len(intervals) == 0 {
		return res
	}
	sort.Sort(IntervalSort(intervals))
	interval := intervals[0]
	for i := 1; i < len(intervals); i++ {
		if intervals[i].Start <= interval.End {
			if intervals[i].End > interval.End {
				interval.End = intervals[i].End
			}
		} else {
			res = append(res, interval)
			interval = intervals[i]
		}
	}
	res = append(res, interval)
	return res
}