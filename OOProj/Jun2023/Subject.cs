using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JUN2023
{
	public abstract class Subject
	{
		protected List<IObserver> observers;
		public Subject()
		{
			observers = new List<IObserver>();
		}
		public void Attach(IObserver observer)
		{
			if (observers.IndexOf(observer) == -1)
				observers.Add(observer);
		}
		public void Detach(IObserver observer)
		{
			observers.Remove(observer);
		}
		public void Notify()
		{
			foreach (IObserver observer in observers)
			{
				observer.Update();
			}	
		}
	}
}
