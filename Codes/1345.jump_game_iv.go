func minJumps(arr []int) int {
	type Node struct {
		idx int
		step int
	}

	l := len(arr)

	que := list.New()
	que.PushBack(&Node{0, 0})

	dump := make([]bool, l)
	table := make(map[int][]int)

	for i, v := range arr {
		table[v] = append(table[v], i)
	}

	dump[0] = true
	var curr *Node
	for que.Len() != 0 {
		curr = que.Front().Value.(*Node)
		que.Remove(que.Front())

		for _, v := range table[arr[curr.idx]] {
			if dump[v] {
				continue
			}

			if v == l - 1 {
				return curr.step + 1
			}

			dump[v] = true
			que.PushBack(&Node{v, curr.step + 1})
		}
		if curr.idx >= 1 && !dump[curr.idx - 1] {
			if curr.idx - 1 == l - 1 {
				return curr.step + 1
			}

			dump[curr.idx - 1] = true
			que.PushBack(&Node{curr.idx - 1, curr.step + 1})
		}
		if curr.idx + 1 < l && !dump[curr.idx + 1] {
			if curr.idx + 1 == l - 1 {
				return curr.step + 1
			}

			dump[curr.idx + 1] = true
			que.PushBack(&Node{curr.idx + 1, curr.step + 1})
		}
	}

	return 0
}
