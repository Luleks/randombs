using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class NemaMestaException : Exception
	{
		public NemaMestaException() { }

		public NemaMestaException(string message) : base(message) { }

		public NemaMestaException(string message, Exception inner) : base(message, inner) { }
	}
}
