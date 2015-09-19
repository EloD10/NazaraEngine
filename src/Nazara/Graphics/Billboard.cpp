// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Engine - Graphics module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Graphics/Billboard.hpp>
#include <Nazara/Graphics/AbstractRenderQueue.hpp>
#include <Nazara/Graphics/AbstractViewer.hpp>
#include <Nazara/Math/Algorithm.hpp>
#include <cstring>
#include <memory>
#include <Nazara/Graphics/Debug.hpp>

void NzBillboard::AddToRenderQueue(NzAbstractRenderQueue* renderQueue, const InstanceData& instanceData) const
{
	if (!m_material)
		return;

	renderQueue->AddBillboard(m_material, instanceData.transformMatrix.GetTranslation(), m_size, m_sinCos, m_color);
}

void NzBillboard::MakeBoundingVolume() const
{
	constexpr float sqrt2 = float(M_SQRT2);

	m_boundingVolume.Set(NzVector3f(0.f), sqrt2*m_size.x*NzVector3f::Right() + sqrt2*m_size.y*NzVector3f::Down());
}

NzBillboardLibrary::LibraryMap NzBillboard::s_library;