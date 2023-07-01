using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	public class ClientBin : Client
	{
		public ClientBin(RandomGenerator random) : base(random) { }
		public override void Display(int val)
		{
			Console.WriteLine("AbsBin: " + Convert.ToString(val, 2));
		}

		public override void Update()
		{
			Display(rGen.Get());
		}
	}
}
