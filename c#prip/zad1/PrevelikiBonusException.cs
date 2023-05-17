using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class PrevelikiBonusException : Exception
	{
		public PrevelikiBonusException() { }
		public PrevelikiBonusException(string message) : base(message) { }
		public PrevelikiBonusException(string message, Exception inner) : base(message, inner) { }
	}
}
