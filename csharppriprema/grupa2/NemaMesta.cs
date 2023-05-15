using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa2
{
	internal class NemaMesta : Exception
	{
		public NemaMesta() : base() { }
		public NemaMesta(string message) : base(message) { }

		public NemaMesta(string message, Exception innerException) : base(message, innerException) { }
	}
}
