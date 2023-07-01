using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	public class RandomGenerator : Subject
	{
		private bool[] reg32bit;
		private Xor xorPerformer;

		public RandomGenerator()
		{
			reg32bit = new bool[32];
			xorPerformer = new Xor();
		}

		public void Init(int value)
		{
			for (int i = 31; i >= 0; i--)
			{
				int temp = value % 2;
				value /= 2;
				reg32bit[i] = (temp == 0) ? false : true;
			}
		}
		public int Get()
		{
			int s = 0;
			for (int i = 0; i < reg32bit.Length; i++)
			{
				if (reg32bit[i])
					s += (int)Math.Pow(2, 31 - i);
			}
			return s;
		}
		public void Next()
		{
			bool val = Xor.PerformXor(reg32bit[8], reg32bit[18], reg32bit[31]);
			for (int i = 31; i >= 1; i--)
				reg32bit[i] = reg32bit[i - 1];
			reg32bit[0] = val;
			Notify();
		}
	}
}
