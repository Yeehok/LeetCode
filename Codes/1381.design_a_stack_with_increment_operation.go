type CustomStack struct {
	stack *list.List
	maxSize int
}


func Constructor(maxSize int) CustomStack {
	return CustomStack{list.New(), maxSize}
}


func (this *CustomStack) Push(x int)  {
	if this.stack.Len() >= this.maxSize {
		return
	}

	this.stack.PushBack(x)
}


func (this *CustomStack) Pop() int {
	if this.stack.Len() <= 0 {
		return -1
	}

	res := this.stack.Back().Value.(int)
	this.stack.Remove(this.stack.Back())
	return res
}


func (this *CustomStack) Increment(k int, val int)  {
	idx := 0
	for e := this.stack.Front(); e != nil && idx < k ; e = e.Next() {
		e.Value = e.Value.(int) + val
		idx++
	}
}


/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */
