
#include <pybind11_json/pybind11_json.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include <pybind11/iostream.h>

namespace py = pybind11;

typedef std::function<Eigen::MatrixXd(double x, double y, double z)> BCFuncV;
typedef std::function<double(double x, double y, double z)> BCFuncS;


namespace
{
	void init_globals()
	{
		static bool initialized = false;

		if (!initialized)
		{
#ifndef WIN32
			setenv("GEO_NO_SIGNAL_HANDLER", "1", 1);
#endif

			GEO::initialize();

#ifdef USE_TBB
			const size_t MB = 1024 * 1024;
			const size_t stack_size = 64 * MB;
			unsigned int num_threads = std::max(1u, std::thread::hardware_concurrency());
			tbb::task_scheduler_init scheduler(num_threads, stack_size);
#endif

			// Import standard command line arguments, and custom ones
			GEO::CmdLine::import_arg_group("standard");
			GEO::CmdLine::import_arg_group("pre");
			GEO::CmdLine::import_arg_group("algo");


			initialized = true;
		}
	}

} // namespace

PYBIND11_MODULE(wmtkpy, m)
{
}
