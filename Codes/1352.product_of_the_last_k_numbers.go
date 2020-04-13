type ProductOfNumbers struct {
	list []int
}

func Constructor() ProductOfNumbers {
	return ProductOfNumbers{}
}


func (this *ProductOfNumbers) Add(num int)  {
	this.list = append(this.list, num)
}


func (this *ProductOfNumbers) GetProduct(k int) (ans int) {
	ans = 1
	for i := len(this.list) - 1; i >= len(this.list) - k; i-- {
		ans *= this.list[i]
	}
	return
}
