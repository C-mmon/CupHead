class DBConnection {
    sqlite3* db;
public:
    DBConnection(const char* path) {
        sqlite3_open(path, &db);
    }
    ~DBConnection() {
        sqlite3_close(db);
    }
};

//When the destructor goes out of scope, connection will automatically close

class FileHandle
{
	int fd;
	FileHandle(const char* path)
	{
		fd = open(path, O_RDONLY);
	}
	~FileHandle()
	{
		if(fd != -1)
		{
			close(fd);
		}
	}
};

//RAII with smart ptr
//We dont neeed to call delete;
std::unique_ptr <MyClass> obj = std::make_unique<MyClass>();


void critical()
{
	std::lock_guard <std::mutex> lock (m);
	doWork();
	//Lock is automatically releease once the function goes out of scope
}
