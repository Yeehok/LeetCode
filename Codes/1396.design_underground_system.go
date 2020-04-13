type UndergroundSystem struct {
	login map[string]map[int]int
	logout map[string]map[int]int
}

func Constructor() UndergroundSystem {
	return UndergroundSystem{make(map[string]map[int]int), make(map[string]map[int]int)}
}

func (this *UndergroundSystem) CheckIn(id int, stationName string, t int)  {
		if this.login[stationName] == nil {
			this.login[stationName] = make(map[int]int)
		}
		this.login[stationName][id] = t
	}

	func (this *UndergroundSystem) CheckOut(id int, stationName string, t int)  {
		if this.logout[stationName] == nil {
			this.logout[stationName] = make(map[int]int)
		}
		this.logout[stationName][id] = t

}

func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
	mapIn := this.login[startStation]
	mapOut := this.logout[endStation]
	cnt := 0.0
	sum := 0.0
	for i, v := range mapIn {
		if t, f := mapOut[i]; f {
			sum += float64(t - v)
			cnt++
		}
	}
	return sum / cnt
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * obj := Constructor();
 * obj.CheckIn(id,stationName,t);
 * obj.CheckOut(id,stationName,t);
 * param_3 := obj.GetAverageTime(startStation,endStation);
 */
