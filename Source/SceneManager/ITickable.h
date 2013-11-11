namespace bammm
{
	class ITickable
	{
		public:
			virtual ~ITickable();
			virtual void tick(float dTime)=0;
	};

	ITickable::~ITickable()
	{
	}
}
