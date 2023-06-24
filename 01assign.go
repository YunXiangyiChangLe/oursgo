package main


func myprint(a int)


func main() {
	var i int
	var sum = 0
	for i = 0; i <= 10; i++ {
		sum += i
		myprint(sum)
	}
}