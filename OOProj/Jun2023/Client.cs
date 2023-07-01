using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	public abstract class Client : IObserver
	{
		protected RandomGenerator rGen;
		public Client(RandomGenerator rGen)
		{
			this.rGen = rGen;
			rGen.Attach(this);
		}
		public abstract void Display(int val);
		public abstract void Update();
	}
}
