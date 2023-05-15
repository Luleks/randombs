using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grupa1
{
	internal class PrevelikiBonus : Exception
	{
		public PrevelikiBonus() : base() { }
		public PrevelikiBonus(string message) : base(message) { }
		public PrevelikiBonus(string message, Exception inner) : base(message, inner) { }
	}
}
