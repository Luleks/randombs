using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	internal class Program
	{
		static void Main(string[] args)
		{
			RandomGenerator rg = new RandomGenerator();
			rg.Init(15);
			Client cHex = new ClientHex(rg);
			Client cMed = new ClientMedian(rg);
			Client cBin = new ClientBin(rg);

			for (int i = 0; i < 3; i++)
			{
				rg.Next();
				Console.WriteLine("--------------------------------------------");
			}

		}
	}
}
