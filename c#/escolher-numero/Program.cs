using System;

namespace escolher_numero
{
    class Program
    {
		static private bool unsupportedInput = false;
		private const string inputWarning1 = "\n\n[aviso] INSIRA APENAS \"1\" OU \"2\"\n[dica]  INSIRA \"q\" PARA FECHAR O PROGRAMA (quit)";
		private const string inputWarning2 = "[aviso] O NÚMERO MÍNIMO NÃO PODE SER MAIOR QUE O NÚMERO MÁXIMO";
		private const string start1 = @"

=========================================================
Que ação pretende executar?

1: Escolher número(s)
2: Mandar uma moeda ao ar (""cara ou coroa"")

(Escolha uma opção introduzindo o número correspondente)
=========================================================";

		static void Main()
        {
            start();
        }

		static void start()
		{
			Console.WriteLine(start1);

			if (unsupportedInput == true)
				Console.WriteLine(inputWarning1);
			
			string initialInput = Console.ReadKey().KeyChar.ToString();

			if (initialInput != "1" || initialInput != "2")
			{
				if (initialInput == "q") {}
				else
				{
				unsupportedInput = true;
				start();
				}
				
			} else {
				unsupportedInput = false;
			}

			switch (initialInput)
			{
				case "1":
					Console.Title = "Números!!!!!!!!";
					num();
					break;
				case "2":
					coin();
					break;
				//default:
			}
		}

		static void num()
		{
			Console.WriteLine("===================================");

			Console.Write("Quantos números quer?\n-> ");
			int drawTimes = int.Parse(Console.ReadLine());

			Console.Write("Qual o número mínimo a obter?\n-> ");
			int minNum = int.Parse(Console.ReadLine());

			Console.Write("Qual o número máximo a obter?\n-> ");
			int maxNum = int.Parse(Console.ReadLine());
			
			Console.WriteLine("===================================\n\n");

			string s, nn;
			if (drawTimes > 1)
			{
				s = "s";
				nn = $" ({drawTimes.ToString()})";
			} else {
				s = null; nn = null;
			}

			if (minNum > maxNum)
			{
				Console.WriteLine(inputWarning2);
				num();
			}
			else
			{
				Console.WriteLine($"======================\nNúmero{s} obtido{s}{nn}:");
			}

			Random rand = new Random();
			for (int i = 1; i <= drawTimes; i++)
			{
				Console.WriteLine(rand.Next(minNum, maxNum+1));
			}

		} // end of num()

		static void coin()
		{

		}
    }
}
