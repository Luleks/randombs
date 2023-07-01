using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	public class Xor
	{
		public static bool PerformXor(params bool[] values)
		{
			bool val = values[0];
			for(int i = 1; i < values.Length; i++)
			{
				val ^= values[i];
			}
			return val;
		}
	}
}
