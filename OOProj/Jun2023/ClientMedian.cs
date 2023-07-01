using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	public class ClientMedian : Client
	{
		private int accumulator;
		private int count;
		public ClientMedian(RandomGenerator randomGenerator) : base(randomGenerator) 
		{
			accumulator = 0;
			count = 0;
		}	
		public override void Display(int val)
		{
			accumulator += val;
			count += 1;
			double median = (double)accumulator / count;
			Console.WriteLine("Median: " + median);
		}

		public override void Update()
		{
			Display(rGen.Get());
		}
	}
}
