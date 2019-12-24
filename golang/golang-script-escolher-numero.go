package main

import (
	"bufio"
	"fmt"
	"os"
)

func start() {
	fmt.Println(`=========================================================
	Que ação pretende executar?
	
	1: Escolher número(s)
	2: Mandar uma moeda ao ar ("cara ou coroa")
	
	(Escolha uma opção introduzindo o número correspondente)
	=========================================================`)
}

func num() {}

func cc() {}

func main() {
	reader := bufio.NewReader(os.Stdin)

	var acaoInicial string = reader.ReadString()

	if acaoInicial == "1" {
		fmt.Println(num)
	} else if acaoInicial == "2" {
		fmt.Println(cc)
	} else {
		fmt.Print(start)
	}
}
