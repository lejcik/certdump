// Copyright (c) 2026 Viliam Lejcik.  Licensed under the MIT License.
// SPDX-License-Identifier: MIT

#pragma once

#include <filesystem>
namespace fs = std::filesystem;

#include <gtest/gtest.h>
using namespace ::testing;

//////////////////////////////////////////////////////////////////////////

class CertParser final
{
public:
	CertParser();
	~CertParser();

	const char *GetOutputFileName() const
	{
		return m_tmpname.c_str();
	}

	void ParseFile();
	bool IsParsed() const
	{
		return m_parsed;
	}

	const std::vector<std::string> &GetContent() const
	{
		return m_content;
	}

private:
	std::string make_tmpname() const;

private:
	// temporary file name
	std::string m_tmpname;
	// file can be parsed only once
	bool m_parsed{false};
	// parsed file content
	std::vector<std::string> m_content;
};

//////////////////////////////////////////////////////////////////////////

class TestFixureBase :
	public ::testing::Test
{
protected:
	/// test certs root path
	const fs::path CERT_ROOT = TEST_CERT_DIR;

	void SetUp() override;
	void TearDown() override;

	// overrider for fs::path argument
	bool DumpCertificate(const fs::path &in, CertParser &out, const std::string &password = {});

	std::string GetObjectType() const;
	std::string GetFormat() const;
	bool FindDecodeFailedMsg() const;
	bool IsFilePasswordProtected() const;

	// plain search
	bool SearchContent(const std::string &pattern) const;
	// regular expression search
	bool SearchContentRE(const std::string& pattern) const;

protected:
	std::unique_ptr<CertParser> m_parser;
};
