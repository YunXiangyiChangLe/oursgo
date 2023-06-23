package main

import "fmt"

var g int = ^20

func swap(x, y int) (int, int) {
   return y, x
}

func main() {

	var a,b int = 10,20
	if a < 20 {
	    fmt.Printf("a Less 20\n" );
	} else {
	    fmt.Printf("a 20\n" );
	}

	var sum int
	for i:=0; i <= 10; i++ {
	    sum += i
	}
	for sum <= 15 {
		sum += sum
	}
	for {}

	var s1,s2 int = "aaa","bbb"
	s3, s4 := swap(s1, s2)

	var g int = 10
	fmt.Printf (": g = %d\n",  g)

	var tmp int= 20
	var p *int
	ip = &a
	fmt.Printf("*ip: %d\n", *ip )
}
