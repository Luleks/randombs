using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	public class ClientHex : Client
	{
		public ClientHex(RandomGenerator rGen) : base(rGen) { }
		public override void Display(int Val)
		{
			Console.WriteLine("Hex: " + Val.ToString("X"));
		}

		public override void Update()
		{
			Display(rGen.Get());
		}
	}
}
