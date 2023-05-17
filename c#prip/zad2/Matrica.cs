using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Matrica<T> where T: Vozilo
	{
		private T[,] matrica;
		private int n;
		private int m;

		public Matrica(int n, int m)
		{
			this.n = n;
			this.m = m;
			matrica = new T[n, m];
		}

		public bool Dodaj(T item)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m - item.BrMesta + 1; j++)
				{
					int k = 0;
					while (k < item.BrMesta && matrica[i, j + k] == null)
						k += 1;
					if (k == item.BrMesta)
					{
						for (k = 0; k < item.BrMesta; k++)
							matrica[i, j + k] = item;
						return true;
					}
				}
			}
			return false;
		}

		public void Ukloni(T item)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (matrica[i, j] == item)
					{
						for (int k = 0; k < item.BrMesta; k++)
							matrica[i, j + k] = null;
						return;
					}
		}

		public T this[int i, int j]
		{
			get { return matrica[i, j]; }
		} 

		public int N
		{
			get { return n; }
		}

		public int M
		{
			get { return m; }
		}
	}
}
