type TweetCounts struct {
	tweets map[string]*list.List
}

func Constructor() TweetCounts {
	return TweetCounts{make(map[string]*list.List)}
}

func (this *TweetCounts) RecordTweet(tweetName string, time int) {
	if this.tweets[tweetName] == nil {
		this.tweets[tweetName] = list.New()
		this.tweets[tweetName].PushBack(time)
		return
	}

	p := this.tweets[tweetName]

	i := p.Front()
	for ; i != nil; i = i.Next() {
		if i.Value.(int) >= time {
			break
		}
	}

	if i == nil {
		p.PushBack(time)
	} else {
		p.InsertBefore(time, i)
	}
}

func (this *TweetCounts) GetTweetCountsPerFrequency(freq string, tweetName string, startTime int, endTime int) (ans []int) {
	if _, f := this.tweets[tweetName]; !f {
		return
	}

	l := this.tweets[tweetName]

	interval := 60
	if freq == "hour" {
		interval *= 60
	} else if freq == "day" {
		interval *= 60 * 24
	}

	for t := startTime; t <= endTime; t += interval {
		cnt := 0

		for i := l.Front(); i != nil; i = i.Next() {
			if i.Value.(int) > endTime || i.Value.(int) >= t + interval {
				break
			} else if i.Value.(int) >= t {
				cnt++
			}
		}

		ans = append(ans, cnt)
	}

	return
}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * obj := Constructor();
 * obj.RecordTweet(tweetName,time);
 * param_2 := obj.GetTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
