/**********************************************************************
 *
 * Copyright(c) 2008 Imagination Technologies Ltd. All rights reserved.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope it will be useful but, except 
 * as otherwise stated in writing, without any warranty; without even the 
 * implied warranty of merchantability or fitness for a particular purpose. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * 
 * The full GNU General Public License is included in this distribution in
 * the file called "COPYING".
 *
 * Contact Information:
 * Imagination Technologies Ltd. <gpl-support@imgtec.com>
 * Home Park Estate, Kings Langley, Herts, WD4 8LZ, UK 
 *
 ******************************************************************************/

#if !defined (__PVRSRV_ERRORS_H__)
#define __PVRSRV_ERRORS_H__

#if defined (__cplusplus)
extern "C" {
#endif

	switch (eError)
	{
		case PVRSRV_OK:									return "No Errors";
		case PVRSRV_ERROR_OUT_OF_MEMORY:				return "PVRSRV_ERROR_OUT_OF_MEMORY - Unable to allocate required memory";
		case PVRSRV_ERROR_TOO_FEW_BUFFERS:				return "PVRSRV_ERROR_TOO_FEW_BUFFERS";
		case PVRSRV_ERROR_INVALID_PARAMS:				return "PVRSRV_ERROR_INVALID_PARAMS";
		case PVRSRV_ERROR_INIT_FAILURE:					return "PVRSRV_ERROR_INIT_FAILURE";
		case PVRSRV_ERROR_CANT_REGISTER_CALLBACK:		return "PVRSRV_ERROR_CANT_REGISTER_CALLBACK";
		case PVRSRV_ERROR_INVALID_DEVICE:				return "PVRSRV_ERROR_INVALID_DEVICE";
		case PVRSRV_ERROR_NOT_OWNER:					return "PVRSRV_ERROR_NOT_OWNER";
		case PVRSRV_ERROR_BAD_MAPPING:					return "PVRSRV_ERROR_BAD_MAPPING";
		case PVRSRV_ERROR_TIMEOUT:						return "PVRSRV_ERROR_TIMEOUT";
		case PVRSRV_ERROR_FLIP_CHAIN_EXISTS:			return "PVRSRV_ERROR_FLIP_CHAIN_EXISTS";
		case PVRSRV_ERROR_INVALID_SWAPINTERVAL:			return "PVRSRV_ERROR_INVALID_SWAPINTERVAL";
		case PVRSRV_ERROR_SCENE_INVALID:				return "PVRSRV_ERROR_SCENE_INVALID";
		case PVRSRV_ERROR_STREAM_ERROR:					return "PVRSRV_ERROR_STREAM_ERROR";
		case PVRSRV_ERROR_FAILED_DEPENDENCIES:			return "PVRSRV_ERROR_FAILED_DEPENDENCIES";
		case PVRSRV_ERROR_CMD_NOT_PROCESSED:			return "PVRSRV_ERROR_CMD_NOT_PROCESSED";
		case PVRSRV_ERROR_CMD_TOO_BIG:					return "PVRSRV_ERROR_CMD_TOO_BIG";
		case PVRSRV_ERROR_DEVICE_REGISTER_FAILED:		return "PVRSRV_ERROR_DEVICE_REGISTER_FAILED";
		case PVRSRV_ERROR_TOOMANYBUFFERS:				return "PVRSRV_ERROR_TOOMANYBUFFERS";
		case PVRSRV_ERROR_NOT_SUPPORTED:				return "PVRSRV_ERROR_NOT_SUPPORTED - fix";
		case PVRSRV_ERROR_PROCESSING_BLOCKED:			return "PVRSRV_ERROR_PROCESSING_BLOCKED";

		case PVRSRV_ERROR_CANNOT_FLUSH_QUEUE:			return "PVRSRV_ERROR_CANNOT_FLUSH_QUEUE";
		case PVRSRV_ERROR_CANNOT_GET_QUEUE_SPACE:		return "PVRSRV_ERROR_CANNOT_GET_QUEUE_SPACE";
		case PVRSRV_ERROR_CANNOT_GET_RENDERDETAILS:		return "PVRSRV_ERROR_CANNOT_GET_RENDERDETAILS";
		case PVRSRV_ERROR_RETRY:						return "PVRSRV_ERROR_RETRY";

		case PVRSRV_ERROR_DDK_VERSION_MISMATCH:			return "PVRSRV_ERROR_DDK_VERSION_MISMATCH";
		case PVRSRV_ERROR_BUILD_MISMATCH:				return "PVRSRV_ERROR_BUILD_MISMATCH";
		case PVRSRV_ERROR_CORE_REVISION_MISMATCH:		return "PVRSRV_ERROR_CORE_REVISION_MISMATCH";

		case PVRSRV_ERROR_UPLOAD_TOO_BIG:				return "PVRSRV_ERROR_UPLOAD_TOO_BIG";

		case PVRSRV_ERROR_INVALID_FLAGS:				return "PVRSRV_ERROR_INVALID_FLAGS";
		case PVRSRV_ERROR_FAILED_TO_REGISTER_PROCESS:	return "PVRSRV_ERROR_FAILED_TO_REGISTER_PROCESS";

		case PVRSRV_ERROR_UNABLE_TO_LOAD_LIBRARY:		return "PVRSRV_ERROR_UNABLE_TO_LOAD_LIBRARY";
		case PVRSRV_ERROR_UNABLE_GET_FUNC_ADDR:			return "PVRSRV_ERROR_UNABLE_GET_FUNC_ADDR";
		case PVRSRV_ERROR_UNLOAD_LIBRARY_FAILED:		return "PVRSRV_ERROR_UNLOAD_LIBRARY_FAILED";

		case PVRSRV_ERROR_BRIDGE_CALL_FAILED:			return "PVRSRV_ERROR_BRIDGE_CALL_FAILED";
		case PVRSRV_ERROR_IOCTL_CALL_FAILED:			return "PVRSRV_ERROR_IOCTL_CALL_FAILED";

		case PVRSRV_ERROR_MMU_CONTEXT_NOT_FOUND:		return "PVRSRV_ERROR_MMU_CONTEXT_NOT_FOUND";
		case PVRSRV_ERROR_BUFFER_DEVICE_NOT_FOUND:		return "PVRSRV_ERROR_BUFFER_DEVICE_NOT_FOUND";
		case PVRSRV_ERROR_BUFFER_DEVICE_ALREADY_PRESENT:return "PVRSRV_ERROR_BUFFER_DEVICE_ALREADY_PRESENT";

		case PVRSRV_ERROR_PCI_DEVICE_NOT_FOUND:			return "PVRSRV_ERROR_PCI_DEVICE_NOT_FOUND";
		case PVRSRV_ERROR_PCI_CALL_FAILED:				return "PVRSRV_ERROR_PCI_CALL_FAILED";
		case PVRSRV_ERROR_PCI_REGION_TOO_SMALL:			return "PVRSRV_ERROR_PCI_REGION_TOO_SMALL";
		case PVRSRV_ERROR_PCI_REGION_UNAVAILABLE:		return "PVRSRV_ERROR_PCI_REGION_UNAVAILABLE";
		case PVRSRV_ERROR_BAD_REGION_SIZE_MISMATCH:		return "PVRSRV_ERROR_BAD_REGION_SIZE_MISMATCH";

		case PVRSRV_ERROR_REGISTER_BASE_NOT_SET:		return "PVRSRV_ERROR_REGISTER_BASE_NOT_SET";

		case PVRSRV_ERROR_FAILED_TO_ALLOC_USER_MEM:		return "PVRSRV_ERROR_FAILED_TO_ALLOC_USER_MEM";
		case PVRSRV_ERROR_FAILED_TO_ALLOC_VP_MEMORY:	return "PVRSRV_ERROR_FAILED_TO_ALLOC_VP_MEMORY";
		case PVRSRV_ERROR_FAILED_TO_MAP_SHARED_PBDESC:	return "PVRSRV_ERROR_FAILED_TO_MAP_SHARED_PBDESC";
		case PVRSRV_ERROR_FAILED_TO_GET_PHYS_ADDR:		return "PVRSRV_ERROR_FAILED_TO_GET_PHYS_ADDR";

		case PVRSRV_ERROR_FAILED_TO_ALLOC_VIRT_MEMORY:	return "PVRSRV_ERROR_FAILED_TO_ALLOC_VIRT_MEMORY";
		case PVRSRV_ERROR_FAILED_TO_COPY_VIRT_MEMORY:	return "PVRSRV_ERROR_FAILED_TO_COPY_VIRT_MEMORY";

		case PVRSRV_ERROR_FAILED_TO_ALLOC_PAGES:		return "PVRSRV_ERROR_FAILED_TO_ALLOC_PAGES";
		case PVRSRV_ERROR_FAILED_TO_FREE_PAGES:			return "PVRSRV_ERROR_FAILED_TO_FREE_PAGES";
		case PVRSRV_ERROR_FAILED_TO_COPY_PAGES:			return "PVRSRV_ERROR_FAILED_TO_COPY_PAGES";
		case PVRSRV_ERROR_UNABLE_TO_LOCK_PAGES:			return "PVRSRV_ERROR_UNABLE_TO_LOCK_PAGES";
		case PVRSRV_ERROR_UNABLE_TO_UNLOCK_PAGES:		return "PVRSRV_ERROR_UNABLE_TO_UNLOCK_PAGES";
		case PVRSRV_ERROR_STILL_MAPPED:					return "PVRSRV_ERROR_STILL_MAPPED";
		case PVRSRV_ERROR_MAPPING_NOT_FOUND:			return "PVRSRV_ERROR_MAPPING_NOT_FOUND";
		case PVRSRV_ERROR_PHYS_ADDRESS_EXCEEDS_32BIT:	return "PVRSRV_ERROR_PHYS_ADDRESS_EXCEEDS_32BIT";
		case PVRSRV_ERROR_FAILED_TO_MAP_PAGE_TABLE:		return "PVRSRV_ERROR_FAILED_TO_MAP_PAGE_TABLE";

		case PVRSRV_ERROR_INVALID_SEGMENT_BLOCK:		return "PVRSRV_ERROR_INVALID_SEGMENT_BLOCK";
		case PVRSRV_ERROR_INVALID_SGXDEVDATA:			return "PVRSRV_ERROR_INVALID_SGXDEVDATA";
		case PVRSRV_ERROR_INVALID_DEVINFO:				return "PVRSRV_ERROR_INVALID_DEVINFO";
		case PVRSRV_ERROR_INVALID_MEMINFO:				return "PVRSRV_ERROR_INVALID_MEMINFO";
		case PVRSRV_ERROR_INVALID_MISCINFO:				return "PVRSRV_ERROR_INVALID_MISCINFO";
		case PVRSRV_ERROR_UNKNOWN_IOCTL:				return "PVRSRV_ERROR_UNKNOWN_IOCTL";
		case PVRSRV_ERROR_INVALID_CONTEXT:				return "PVRSRV_ERROR_INVALID_CONTEXT";
		case PVRSRV_ERROR_UNABLE_TO_DESTROY_CONTEXT:	return "PVRSRV_ERROR_UNABLE_TO_DESTROY_CONTEXT";
		case PVRSRV_ERROR_INVALID_HEAP:					return "PVRSRV_ERROR_INVALID_HEAP";
		case PVRSRV_ERROR_INVALID_KERNELINFO:			return "PVRSRV_ERROR_INVALID_KERNELINFO";
		case PVRSRV_ERROR_UNKNOWN_POWER_STATE:			return "PVRSRV_ERROR_UNKNOWN_POWER_STATE";
		case PVRSRV_ERROR_INVALID_HANDLE_TYPE:			return "PVRSRV_ERROR_INVALID_HANDLE_TYPE";
		case PVRSRV_ERROR_INVALID_WRAP_TYPE:			return "PVRSRV_ERROR_INVALID_WRAP_TYPE";
		case PVRSRV_ERROR_INVALID_PHYS_ADDR:			return "PVRSRV_ERROR_INVALID_PHYS_ADDR";
		case PVRSRV_ERROR_INVALID_CPU_ADDR:				return "PVRSRV_ERROR_INVALID_CPU_ADDR";
		case PVRSRV_ERROR_INVALID_HEAPINFO:				return "PVRSRV_ERROR_INVALID_HEAPINFO";
		case PVRSRV_ERROR_INVALID_PERPROC:				return "PVRSRV_ERROR_INVALID_PERPROC";
		case PVRSRV_ERROR_FAILED_TO_RETRIEVE_HEAPINFO:	return "PVRSRV_ERROR_FAILED_TO_RETRIEVE_HEAPINFO";
		case PVRSRV_ERROR_INVALID_MAP_REQUEST:			return "PVRSRV_ERROR_INVALID_MAP_REQUEST";
		case PVRSRV_ERROR_INVALID_UNMAP_REQUEST:		return "PVRSRV_ERROR_INVALID_UNMAP_REQUEST";
		case PVRSRV_ERROR_UNABLE_TO_FIND_MAPPING_HEAP:	return "PVRSRV_ERROR_UNABLE_TO_FIND_MAPPING_HEAP";
		case PVRSRV_ERROR_MAPPING_STILL_IN_USE:			return "PVRSRV_ERROR_MAPPING_STILL_IN_USE";

		case PVRSRV_ERROR_EXCEEDED_HW_LIMITS:			return "PVRSRV_ERROR_EXCEEDED_HW_LIMITS";
		case PVRSRV_ERROR_NO_STAGING_BUFFER_ALLOCATED:	return "PVRSRV_ERROR_NO_STAGING_BUFFER_ALLOCATED";

		case PVRSRV_ERROR_UNABLE_TO_CREATE_PERPROC_AREA:return "PVRSRV_ERROR_UNABLE_TO_CREATE_PERPROC_AREA";
		case PVRSRV_ERROR_UNABLE_TO_CREATE_EVENT:		return "PVRSRV_ERROR_UNABLE_TO_CREATE_EVENT";
		case PVRSRV_ERROR_UNABLE_TO_ENABLE_EVENT:		return "PVRSRV_ERROR_UNABLE_TO_ENABLE_EVENT";
		case PVRSRV_ERROR_UNABLE_TO_REGISTER_EVENT:		return "PVRSRV_ERROR_UNABLE_TO_REGISTER_EVENT";
		case PVRSRV_ERROR_UNABLE_TO_DESTROY_EVENT:		return "PVRSRV_ERROR_UNABLE_TO_DESTROY_EVENT";
		case PVRSRV_ERROR_UNABLE_TO_CREATE_THREAD:		return "PVRSRV_ERROR_UNABLE_TO_CREATE_THREAD";
		case PVRSRV_ERROR_UNABLE_TO_CLOSE_THREAD:		return "PVRSRV_ERROR_UNABLE_TO_CLOSE_THREAD";
		case PVRSRV_ERROR_THREAD_READ_ERROR:			return "PVRSRV_ERROR_THREAD_READ_ERROR";
		case PVRSRV_ERROR_UNABLE_TO_REGISTER_ISR_HANDLER:return "PVRSRV_ERROR_UNABLE_TO_REGISTER_ISR_HANDLER";
		case PVRSRV_ERROR_UNABLE_TO_INSTALL_ISR:		return "PVRSRV_ERROR_UNABLE_TO_INSTALL_ISR";
		case PVRSRV_ERROR_UNABLE_TO_UNINSTALL_ISR:		return "PVRSRV_ERROR_UNABLE_TO_UNINSTALL_ISR";
		case PVRSRV_ERROR_ISR_ALREADY_INSTALLED:		return "PVRSRV_ERROR_ISR_ALREADY_INSTALLED";
		case PVRSRV_ERROR_ISR_NOT_INSTALLED:			return "PVRSRV_ERROR_ISR_NOT_INSTALLED";
		case PVRSRV_ERROR_UNABLE_TO_INITIALISE_INTERRUPT:return "PVRSRV_ERROR_UNABLE_TO_INITIALISE_INTERRUPT";
		case PVRSRV_ERROR_UNABLE_TO_RETRIEVE_INFO:		return "PVRSRV_ERROR_UNABLE_TO_RETRIEVE_INFO";
		case PVRSRV_ERROR_UNABLE_TO_DO_BACKWARDS_BLIT:	return "PVRSRV_ERROR_UNABLE_TO_DO_BACKWARDS_BLIT";
		case PVRSRV_ERROR_UNABLE_TO_CLOSE_SERVICES:		return "PVRSRV_ERROR_UNABLE_TO_CLOSE_SERVICES";
		case PVRSRV_ERROR_UNABLE_TO_REGISTER_CONTEXT:	return "PVRSRV_ERROR_UNABLE_TO_REGISTER_CONTEXT";
		case PVRSRV_ERROR_UNABLE_TO_REGISTER_RESOURCE:	return "PVRSRV_ERROR_UNABLE_TO_REGISTER_RESOURCE";

		case PVRSRV_ERROR_INVALID_CCB_COMMAND:			return "PVRSRV_ERROR_INVALID_CCB_COMMAND";

		case PVRSRV_ERROR_UNABLE_TO_LOCK_RESOURCE:		return "PVRSRV_ERROR_UNABLE_TO_LOCK_RESOURCE";
		case PVRSRV_ERROR_INVALID_LOCK_ID:				return "PVRSRV_ERROR_INVALID_LOCK_ID";
		case PVRSRV_ERROR_RESOURCE_NOT_LOCKED:			return "PVRSRV_ERROR_RESOURCE_NOT_LOCKED";

		case PVRSRV_ERROR_FLIP_FAILED:					return "PVRSRV_ERROR_FLIP_FAILED";
		case PVRSRV_ERROR_UNBLANK_DISPLAY_FAILED:		return "PVRSRV_ERROR_UNBLANK_DISPLAY_FAILED";

		case PVRSRV_ERROR_TIMEOUT_POLLING_FOR_VALUE:	return "PVRSRV_ERROR_TIMEOUT_POLLING_FOR_VALUE";

		case PVRSRV_ERROR_CREATE_RENDER_CONTEXT_FAILED:	return "PVRSRV_ERROR_CREATE_RENDER_CONTEXT_FAILED";
		case PVRSRV_ERROR_UNKNOWN_PRIMARY_FRAG:			return "PVRSRV_ERROR_UNKNOWN_PRIMARY_FRAG";
		case PVRSRV_ERROR_UNEXPECTED_SECONDARY_FRAG:	return "PVRSRV_ERROR_UNEXPECTED_SECONDARY_FRAG";
		case PVRSRV_ERROR_UNEXPECTED_PRIMARY_FRAG:		return "PVRSRV_ERROR_UNEXPECTED_PRIMARY_FRAG";

		case PVRSRV_ERROR_UNABLE_TO_INSERT_FENCE_ID:	return "PVRSRV_ERROR_UNABLE_TO_INSERT_FENCE_ID";

		case PVRSRV_ERROR_BLIT_SETUP_FAILED:			return "PVRSRV_ERROR_BLIT_SETUP_FAILED";

		case PVRSRV_ERROR_PDUMP_NOT_AVAILABLE:			return "PVRSRV_ERROR_PDUMP_NOT_AVAILABLE";
		case PVRSRV_ERROR_PDUMP_BUFFER_FULL:			return "PVRSRV_ERROR_PDUMP_BUFFER_FULL";
		case PVRSRV_ERROR_PDUMP_BUF_OVERFLOW:			return "PVRSRV_ERROR_PDUMP_BUF_OVERFLOW";
		case PVRSRV_ERROR_PDUMP_NOT_ACTIVE:				return "PVRSRV_ERROR_PDUMP_NOT_ACTIVE";
		case PVRSRV_ERROR_INCOMPLETE_LINE_OVERLAPS_PAGES:return "PVRSRV_ERROR_INCOMPLETE_LINE_OVERLAPS_PAGES";

		case PVRSRV_ERROR_MUTEX_DESTROY_FAILED:			return "PVRSRV_ERROR_MUTEX_DESTROY_FAILED";
		case PVRSRV_ERROR_MUTEX_INTERRUPTIBLE_ERROR:	return "PVRSRV_ERROR_MUTEX_INTERRUPTIBLE_ERROR";

		case PVRSRV_ERROR_INSUFFICIENT_SCRIPT_SPACE:	return "PVRSRV_ERROR_INSUFFICIENT_SCRIPT_SPACE";
		case PVRSRV_ERROR_INSUFFICIENT_SPACE_FOR_COMMAND:return "PVRSRV_ERROR_INSUFFICIENT_SPACE_FOR_COMMAND";

		case PVRSRV_ERROR_PROCESS_NOT_INITIALISED:		return "PVRSRV_ERROR_PROCESS_NOT_INITIALISED";
		case PVRSRV_ERROR_PROCESS_NOT_FOUND:			return "PVRSRV_ERROR_PROCESS_NOT_FOUND";
		case PVRSRV_ERROR_SRV_CONNECT_FAILED:			return "PVRSRV_ERROR_SRV_CONNECT_FAILED";
		case PVRSRV_ERROR_SRV_DISCONNECT_FAILED:		return "PVRSRV_ERROR_SRV_DISCONNECT_FAILED";
		case PVRSRV_ERROR_DEINT_PHASE_FAILED:			return "PVRSRV_ERROR_DEINT_PHASE_FAILED";
		case PVRSRV_ERROR_INIT2_PHASE_FAILED:			return "PVRSRV_ERROR_INIT2_PHASE_FAILED";

		case PVRSRV_ERROR_NO_DC_DEVICES_FOUND:			return "PVRSRV_ERROR_NO_DC_DEVICES_FOUND";
		case PVRSRV_ERROR_UNABLE_TO_OPEN_DC_DEVICE:		return "PVRSRV_ERROR_UNABLE_TO_OPEN_DC_DEVICE";
		case PVRSRV_ERROR_UNABLE_TO_REMOVE_DEVICE:		return "PVRSRV_ERROR_UNABLE_TO_REMOVE_DEVICE";
		case PVRSRV_ERROR_NO_DEVICEDATA_FOUND:			return "PVRSRV_ERROR_NO_DEVICEDATA_FOUND";
		case PVRSRV_ERROR_NO_DEVICENODE_FOUND:			return "PVRSRV_ERROR_NO_DEVICENODE_FOUND";
		case PVRSRV_ERROR_NO_CLIENTNODE_FOUND:			return "PVRSRV_ERROR_NO_CLIENTNODE_FOUND";
		case PVRSRV_ERROR_FAILED_TO_PROCESS_QUEUE:		return "PVRSRV_ERROR_FAILED_TO_PROCESS_QUEUE";

		case PVRSRV_ERROR_UNABLE_TO_INIT_TASK:			return "PVRSRV_ERROR_UNABLE_TO_INIT_TASK";
		case PVRSRV_ERROR_UNABLE_TO_SCHEDULE_TASK:		return "PVRSRV_ERROR_UNABLE_TO_SCHEDULE_TASK";
		case PVRSRV_ERROR_UNABLE_TO_KILL_TASK:			return "PVRSRV_ERROR_UNABLE_TO_KILL_TASK";

		case PVRSRV_ERROR_UNABLE_TO_ENABLE_TIMER:		return "PVRSRV_ERROR_UNABLE_TO_ENABLE_TIMER";
		case PVRSRV_ERROR_UNABLE_TO_DISABLE_TIMER:		return "PVRSRV_ERROR_UNABLE_TO_DISABLE_TIMER";
		case PVRSRV_ERROR_UNABLE_TO_REMOVE_TIMER:		return "PVRSRV_ERROR_UNABLE_TO_REMOVE_TIMER";

		case PVRSRV_ERROR_UNKNOWN_PIXEL_FORMAT:			return "PVRSRV_ERROR_UNKNOWN_PIXEL_FORMAT";
		case PVRSRV_ERROR_UNKNOWN_SCRIPT_OPERATION:		return "PVRSRV_ERROR_UNKNOWN_SCRIPT_OPERATION";

		case PVRSRV_ERROR_HANDLE_INDEX_OUT_OF_RANGE:	return "PVRSRV_ERROR_HANDLE_INDEX_OUT_OF_RANGE";
		case PVRSRV_ERROR_HANDLE_NOT_ALLOCATED:			return "PVRSRV_ERROR_HANDLE_NOT_ALLOCATED";
		case PVRSRV_ERROR_HANDLE_TYPE_MISMATCH:			return "PVRSRV_ERROR_HANDLE_TYPE_MISMATCH";
		case PVRSRV_ERROR_UNABLE_TO_ADD_HANDLE:			return "PVRSRV_ERROR_UNABLE_TO_ADD_HANDLE";
		case PVRSRV_ERROR_HANDLE_NOT_SHAREABLE:			return "PVRSRV_ERROR_HANDLE_NOT_SHAREABLE";
		case PVRSRV_ERROR_HANDLE_NOT_FOUND:				return "PVRSRV_ERROR_HANDLE_NOT_FOUND";
		case PVRSRV_ERROR_INVALID_SUBHANDLE:			return "PVRSRV_ERROR_INVALID_SUBHANDLE";
		case PVRSRV_ERROR_HANDLE_BATCH_IN_USE:			return "PVRSRV_ERROR_HANDLE_BATCH_IN_USE";
		case PVRSRV_ERROR_HANDLE_BATCH_COMMIT_FAILURE:	return "PVRSRV_ERROR_HANDLE_BATCH_COMMIT_FAILURE";

		case PVRSRV_ERROR_UNABLE_TO_CREATE_HASH_TABLE:	return "PVRSRV_ERROR_UNABLE_TO_CREATE_HASH_TABLE";
		case PVRSRV_ERROR_INSERT_HASH_TABLE_DATA_FAILED:return "PVRSRV_ERROR_INSERT_HASH_TABLE_DATA_FAILED";

		case PVRSRV_ERROR_UNSUPPORTED_BACKING_STORE:	return "PVRSRV_ERROR_UNSUPPORTED_BACKING_STORE";
		case PVRSRV_ERROR_UNABLE_TO_DESTROY_BM_HEAP:	return "PVRSRV_ERROR_UNABLE_TO_DESTROY_BM_HEAP";

		case PVRSRV_ERROR_UNKNOWN_INIT_SERVER_STATE:	return "PVRSRV_ERROR_UNKNOWN_INIT_SERVER_STATE";

		case PVRSRV_ERROR_NO_FREE_DEVICEIDS_AVALIABLE:	return "PVRSRV_ERROR_NO_FREE_DEVICEIDS_AVALIABLE";
		case PVRSRV_ERROR_INVALID_DEVICEID:				return "PVRSRV_ERROR_INVALID_DEVICEID";
		case PVRSRV_ERROR_DEVICEID_NOT_FOUND:			return "PVRSRV_ERROR_DEVICEID_NOT_FOUND";

		case PVRSRV_ERROR_MEMORY_TEST_FAILED:			return "PVRSRV_ERROR_MEMORY_TEST_FAILED";
		case PVRSRV_ERROR_CPUPADDR_TEST_FAILED:			return "PVRSRV_ERROR_CPUPADDR_TEST_FAILED";
		case PVRSRV_ERROR_COPY_TEST_FAILED:				return "PVRSRV_ERROR_COPY_TEST_FAILED";

		case PVRSRV_ERROR_SEMAPHORE_NOT_INITIALISED:	return "PVRSRV_ERROR_SEMAPHORE_NOT_INITIALISED";

		case PVRSRV_ERROR_UNABLE_TO_RELEASE_CLOCK:		return "PVRSRV_ERROR_UNABLE_TO_RELEASE_CLOCK";
		case PVRSRV_ERROR_CLOCK_REQUEST_FAILED:			return "PVRSRV_ERROR_CLOCK_REQUEST_FAILED";
		case PVRSRV_ERROR_DISABLE_CLOCK_FAILURE:		return "PVRSRV_ERROR_DISABLE_CLOCK_FAILURE";
		case PVRSRV_ERROR_UNABLE_TO_SET_CLOCK_RATE:		return "PVRSRV_ERROR_UNABLE_TO_SET_CLOCK_RATE";
		case PVRSRV_ERROR_UNABLE_TO_ROUND_CLOCK_RATE:	return "PVRSRV_ERROR_UNABLE_TO_ROUND_CLOCK_RATE";
		case PVRSRV_ERROR_UNABLE_TO_ENABLE_CLOCK:		return "PVRSRV_ERROR_UNABLE_TO_ENABLE_CLOCK";
		case PVRSRV_ERROR_UNABLE_TO_GET_CLOCK:			return "PVRSRV_ERROR_UNABLE_TO_GET_CLOCK";
		case PVRSRV_ERROR_UNABLE_TO_GET_PARENT_CLOCK:	return "PVRSRV_ERROR_UNABLE_TO_GET_PARENT_CLOCK";
		case PVRSRV_ERROR_UNABLE_TO_GET_SYSTEM_CLOCK:	return "PVRSRV_ERROR_UNABLE_TO_GET_SYSTEM_CLOCK";

		case PVRSRV_ERROR_UNKNOWN_SGL_ERROR:			return "PVRSRV_ERROR_UNKNOWN_SGL_ERROR";
	    case PVRSRV_ERROR_BAD_SYNC_STATE:               return "PVRSRV_ERROR_BAD_SYNC_STATE";

		case PVRSRV_ERROR_FORCE_I32:					return "PVRSRV_ERROR_FORCE_I32";

		default:
			return "Unknown PVRSRV error number";
	}

#if defined (__cplusplus)
}
#endif
#endif 

