using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp3
{
	internal class Kolekcija<T> where T: Stavka
	{
		private List<T> items;

		public Kolekcija()
		{
			items = new List<T>();
		}

		public void Add(T item)
		{
			items.Add(item);
		}

		public T this[int i]
		{
			get { return items[i]; }
			set { items[i] = value; }
		}

		public int Count
		{
			get { return items.Count; }
		}
	}
}
