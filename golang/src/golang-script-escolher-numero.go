package main

import (
	"bufio"
	"fmt"
	"os"
)

var acaoInicial string

func main() {
	reader := bufio.NewReader(os.Stdin)

	start()

	acaoInicial, _ = reader.ReadString('\n')

	if acaoInicial == "1" {
		num()
	} else if acaoInicial == "2" {
		cc()
	} else {
		start()
	}
}

func start() {
	fmt.Println(`

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar ("cara ou coroa")

(Escolha uma opção introduzindo o número correspondente)
=========================================================`)
}

func num() {}

func cc() {}
