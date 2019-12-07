/*
	//data get and put 
*/

#include <iostream>

typedef struct _VideoData {
	uint8_t* vdBuffer;
	int      vdLen;
}VideoData;

namespace ss {

	class IVideoPutHandler
	{
	public:
		virtual bool onPutData(std::string sourceID, VideoData &videoData) = 0;
		virtual ~IVideoPutHandler() {};
	};

	class IVideoGetHandler
	{
	public:
		virtual bool onGetData(std::string sourceID, VideoData &videoData) = 0;
		virtual ~IVideoGetHandler() {};
	};

	template<typename TPutHandler, typename TGetHandler, typename TMediaSource>
	class MediaSourceManager
	{
	public:
		virtual ~MediaSourceManager();
		void addPutHandler(const std::string &sourceID, TPutHandler *handler);
		bool removePutHandler(const std::string &sourceID, TPutHandler *handler);
		void addHandler(const std::string &sourceID, TGetHandler *handler);
		void removeGetHandler(const std::string &sourceID, TGetHandler *handler);
	};
}