func watchedVideosByFriends(watchedVideos [][]string, friends [][]int, id int, level int) (res []string) {
	var source []int
	source = append(source, id)
	var total_dump = make(map[int]bool)
	for i := 0; i < level; i++ {
		var dump = make(map[int]bool)
		for _, v := range source {
			for _, v2 := range friends[v] {
				dump[v2] = true
			}
		}
		source = make([]int, 0)
		for k := range dump {
			if k == id {
				continue
			}
			_, found := total_dump[k]
			if found {
				continue
			}
			source = append(source, k)
			total_dump[k] = true
		}
	}
	var video = make(map[string]int)
	for _, v := range source {
		for _, v2 := range watchedVideos[v] {
			video[v2]++
		}
	}
	for len(video) > 0 {
		var min = 80000
		var r string
		for k, v := range video {
			if v < min {
				min = v
				r = k
			} else if v == min && r > k {
				r = k
			}
		}
		if r == "" {
			continue
		}
		delete(video, r)
		res = append(res, r)
	}
	return
}
