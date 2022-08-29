/*
 * Copyright (c) 2022 Intelligent Semantic Systems LLC, All rights reserved.
 * Author Kseniya Bantsevich
 */

#pragma once

#include <memory>

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_memory.hpp"

namespace messageReplyModule
{
class MessageHistoryGenerator
{
public:
  explicit MessageHistoryGenerator(ScMemoryContext * ms_context);

  void addMessageToDialog(const ScAddr & dialogAddr, const ScAddr & messageAddr);

  std::unique_ptr<ScTemplate> createNotFirstMessageInDialogTemplate(
      const ScAddr & dialogAddr,
      const ScAddr & lastMessageAddr,
      const ScAddr & messageAddr);

  static std::unique_ptr<ScTemplate> createFirstMessageInDialogTemplate(
      const ScAddr & dialogAddr,
      const ScAddr & messageAddr);

private:
  ScMemoryContext * context;
};

}  // namespace messageReplyModule
