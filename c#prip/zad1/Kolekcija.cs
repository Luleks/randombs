using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class Kolekcija<T> where T: Zaposleni
	{
		private List<T> items;

		public Kolekcija()
		{
			items = new List<T>();
		}

		public void addItem(T item)
		{
			items.Add(item);
		}

		public int Count
		{
			get { return items.Count; }
		}

		public T this[int i]
		{
			get { return items[i]; }
		}
	}
}
