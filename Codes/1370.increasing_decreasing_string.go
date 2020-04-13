func sortString(s string) (ans string) {
	dump := make(map[int]bool)
	appendMin := func(out *rune) bool {
		*out = math.MaxInt32
		minI := 0
		for i, v := range s {
			if !dump[i] && v < *out {
				*out = v
				minI = i
			}
		}

		if *out != math.MaxInt32 {
			dump[minI] = true
			return true
		}

		return false
	}

	appendMax := func(out *rune) bool {
		*out = -1
		maxI := 0
		for i, v := range s {
			if !dump[i] && v > *out {
				*out = v
				maxI = i
			}
		}

		if *out != -1 {
			dump[maxI] = true
			return true
		}

		return false
	}

	appendMinMax := func(out *rune, refer rune) bool {
		*out = math.MaxInt32
		minI := 0
		for i, v := range s {
			if !dump[i] && v > refer && v < *out {
				*out = v
				minI = i
			}
		}

		if *out != math.MaxInt32 {
			dump[minI] = true
			return true
		}

		return false
	}

	appendMaxMin := func(out *rune, refer rune) bool {
		*out = -1
		maxI := 0
		for i, v := range s {
			if !dump[i] && v < refer && v > *out {
				*out = v
				maxI = i
			}
		}

		if *out != -1 {
			dump[maxI] = true
			return true
		}

		return false
	}

	var res rune
	var last rune
	l := len(s)
	op := 0
	for i := 0; i < l; i++ {
		if op == 0 {
			if appendMin(&res) {
				ans += string(res)
				last = res
				op = 1
			}
		} else if op == 1 {
			if appendMinMax(&res, last) {
				ans += string(res)
				last = res
			} else {
				i--
				op = 2
			}
		} else if op == 2 {
			if appendMax(&res) {
				ans += string(res)
				last = res
				op = 3
			}
		} else if op == 3 {
			if appendMaxMin(&res, last) {
				ans += string(res)
				last = res
			} else {
				i--
				op = 0
			}
		}
	}

	return
}
