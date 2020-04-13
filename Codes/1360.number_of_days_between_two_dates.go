func daysBetweenDates(date1 string, date2 string) (ans int) {
	var getNum = func(str string, beg int, end int) (res int32) {
		for i := beg; i < end; i++ {
			res *= 10
			res += int32(str[i] - '0')
		}

		return
	}

	month := []int{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

	var getDay = func(y int32, m int32) int {
		if (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 {
			if m == 2 {
				return 29
			}
		}
		return month[m]
	}

	year1 := getNum(date1, 0, 4)
	month1 := getNum(date1, 5, 7)
	day1 := getNum(date1, 8, 10)

	year2 := getNum(date2, 0, 4)
	month2 := getNum(date2, 5, 7)
	day2 := getNum(date2, 8, 10)

	if year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2) {
		year1 = atomic.SwapInt32(&year2, year1)
		month1 = atomic.SwapInt32(&month2, month1)
		day1 = atomic.SwapInt32(&day2, day1)
	}

	thisMonth := int32(getDay(year1, month1))
	for true {
		if year1 >= year2 && month1 >= month2 && day1 >= day2 {
			break
		}

		ans++

		day1++
		if day1 > thisMonth {
			day1 = 1
			month1++
			if month1 > 12 {
				month1 = 1
				year1++
			}
			thisMonth = int32(getDay(year1, month1))
		}
	}

	return
}
