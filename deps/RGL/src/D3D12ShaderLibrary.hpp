#pragma once
#include <RGL/Types.hpp>
#include <RGL/ShaderLibrary.hpp>
#include <filesystem>
#include <span>
#include <cstdint>
#include <directx/d3d12.h>
#include <directx/d3dx12.h>
#include "RGLD3D12.hpp"
#include "D3D12PipelineShared.hpp"

namespace RGL {

	struct ShaderLibraryD3D12 : public IShaderLibrary {
		Microsoft::WRL::ComPtr<ID3DBlob> shaderBlob;
		CD3DX12_SHADER_BYTECODE shaderBytecode;

		BufferBindingStore bufferBindingStore;

		ShaderLibraryD3D12();
		ShaderLibraryD3D12(const std::span<const uint8_t, std::dynamic_extent>);
		ShaderLibraryD3D12(const std::string_view, const FromSourceConfig& config);
		ShaderLibraryD3D12(const std::filesystem::path& path);

		void InitFromBytes(const std::span<const uint8_t, std::dynamic_extent>);

		~ShaderLibraryD3D12() {}
	private:
		void ShaderReflect();
	};
}
