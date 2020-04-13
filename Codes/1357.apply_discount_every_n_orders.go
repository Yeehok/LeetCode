type Cashier struct {
	curCustomer int
	discountCustomer int
	discount float64
	products map[int]int
	prices []int
}


func Constructor(n int, discount int, products []int, prices []int) Cashier {
	productsMap := make(map[int]int)

	for i, v := range products {
		productsMap[v] = i
	}

	return Cashier{0,
		n,
		float64(100 - discount) / 100.0,
		productsMap,
		prices,
	}
}


func (this *Cashier) GetBill(product []int, amount []int) (price float64) {
	this.curCustomer++

	for i, v := range product {
		price += float64(this.prices[this.products[v]] * amount[i])
	}

	if this.curCustomer == this.discountCustomer {
		price *= this.discount
		this.curCustomer = 0
	}

	return
}
