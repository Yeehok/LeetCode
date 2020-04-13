func checkOverlap(radius int, x_center int, y_center int, x1 int, y1 int, x2 int, y2 int) bool {
	c_x := (float64(x1) + float64(x2)) / 2
	c_y := (float64(y1) + float64(y2)) / 2

	f_xc := float64(x_center) - c_x
	f_yc := float64(y_center) - c_y
	if f_xc < 0 {
		f_xc = -1 * f_xc
	}

	if f_yc < 0 {
		f_yc = -1 * f_yc
	}

	f_x2 := float64(x2) - c_x
	f_y2 := float64(y2) - c_y

	var dis float64
	if f_xc > f_x2 && f_yc > f_y2 {
		a := f_xc - f_x2
		b := f_yc - f_y2

		dis = a * a + b * b
	} else if f_xc > f_x2 {
		a := f_xc - f_x2
		b := 0.0

		dis = a * a + b * b
	} else if f_yc > f_y2 {
		a := 0.0
		b := f_yc - f_y2

		dis = a * a + b * b
	} else {
		return true
	}

	return dis <= float64(radius * radius)
}
