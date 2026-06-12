# 排查后发现问题在前端这是GitHub上其名称为__tests__/nsfwImageGeneration.test.

**分类**：AI工具与酒馆
**来源**：DeepSeek Chat 导出
**来源平台**：DeepSeek
**原始文件**：NSFW文生图失败原因分析.md
**包含轮次**：3 - 3

---

# 用户：
排查后发现问题在前端这是GitHub上其名称为__tests__/nsfwImageGeneration.test.ts的代码分析一下是否有问题import { afterEach, describe, expect, it, vi } from 'vitest';
import {
    获取NSFW文生图接口配置,
    生图接口支持NSFW,
    获取文生图接口配置,
    获取场景文生图接口配置,
    用已发现ComfyUI后端替换地址,
    刷新已发现ComfyUI后端缓存,
    清空已发现ComfyUI后端缓存,
    接口配置是否可用,
    规范化接口设置,
    创建空接口设置,
    默认功能模型占位
} from '../utils/apiConfig';
import type { 接口设置结构 } from '../models/system';
import {
    构建运行时额外提示词,
    构建文生图运行时额外提示词,
    默认NSFW模式提示词,
    默认文生图NSFW模式提示词
} from '../prompts/runtime/nsfw';

const 构建测试接口设置 = (overrides?: Partial<{
    文生图功能启用: boolean;
    文生图后端类型: string;
    文生图模型使用模型: string;
    文生图模型API地址: string;
    文生图模型API密钥: string;
    NSFW生图独立接口启用: boolean;
    NSFW生图后端类型: string;
    NSFW生图模型使用模型: string;
    NSFW生图模型API地址: string;
    NSFW生图模型API密钥: string;
    NSFWComfyUI工作流JSON: string;
    场景生图独立接口启用: boolean;
    场景生图后端类型: string;
    主接口baseUrl: string;
    主接口apiKey: string;
    主接口model: string;
}>): 接口设置结构 => {
    return {
        activeConfigId: 'default',
        configs: [{
            id: 'default',
            名称: '默认配置',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: overrides?.主接口baseUrl || 'https://api.example.com',
            apiKey: overrides?.主接口apiKey || 'test-key',
            model: overrides?.主接口model || 'gpt-4',
            maxTokens: 4096,
            temperature: 0.7,
            createdAt: Date.now(),
            updatedAt: Date.now()
        }],
        功能模型占位: {
            ...默认功能模型占位,
            文生图功能启用: overrides?.文生图功能启用 ?? true,
            文生图后端类型: (overrides?.文生图后端类型 as any) || 'sd_webui',
            文生图模型使用模型: overrides?.文生图模型使用模型 || 'sd-v1',
            文生图模型API地址: overrides?.文生图模型API地址 || 'http://localhost:7860',
            文生图模型API密钥: overrides?.文生图模型API密钥 || '',
            NSFW生图独立接口启用: overrides?.NSFW生图独立接口启用 ?? false,
            NSFW生图后端类型: (overrides?.NSFW生图后端类型 as any) || 'sd_webui',
            NSFW生图模型使用模型: overrides?.NSFW生图模型使用模型 || '',
            NSFW生图模型API地址: overrides?.NSFW生图模型API地址 || '',
            NSFW生图模型API密钥: overrides?.NSFW生图模型API密钥 || '',
            NSFWComfyUI工作流JSON: overrides?.NSFWComfyUI工作流JSON || '',
            场景生图独立接口启用: overrides?.场景生图独立接口启用 ?? false,
            场景生图后端类型: (overrides?.场景生图后端类型 as any) || 'sd_webui'
        }
    };
};

afterEach(() => {
    清空已发现ComfyUI后端缓存();
    vi.restoreAllMocks();
});

const 模拟已发现ComfyUI后端 = async (items: Array<{ id: string; url: string; lastHeartbeatAt: string }>) => {
    vi.spyOn(globalThis, 'fetch').mockResolvedValue({
        ok: true,
        json: async () => ({
            ok: true,
            items: items.map((item) => ({
                id: item.id,
                customerId: 'test',
                label: item.id,
                backendType: 'comfyui',
                port: 8188,
                url: item.url,
                detectedAt: item.lastHeartbeatAt,
                lastHeartbeatAt: item.lastHeartbeatAt,
                source: 'registry'
            }))
        }),
        text: async () => ''
    } as Response);
    await 刷新已发现ComfyUI后端缓存('https://registry.example', 'token');
};

describe('生图接口支持NSFW', () => {
    it('returns false for null config', () => {
        expect(生图接口支持NSFW(null)).toBe(false);
    });

    it('returns false for OpenAI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai',
            协议覆盖: 'auto',
            baseUrl: 'https://api.openai.com',
            apiKey: 'key',
            model: 'dall-e-3',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'openai',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'openai_images',
            图片接口路径: '/v1/images/generations',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: false
        })).toBe(false);
    });

    it('returns true for SD WebUI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'http://localhost:7860',
            apiKey: '',
            model: '',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'sd_webui',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'sd_txt2img',
            图片接口路径: '/sdapi/v1/txt2img',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });

    it('returns true for ComfyUI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'http://localhost:8188',
            apiKey: '',
            model: '',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'comfyui',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'comfyui_prompt',
            图片接口路径: '/prompt',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });

    it('returns true for NovelAI backend', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'novelai',
            协议覆盖: 'auto',
            baseUrl: 'https://image.novelai.net',
            apiKey: 'token',
            model: 'nai-diffusion-4',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'novelai',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'novelai_generate',
            图片接口路径: '/ai/generate-image',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });

    it('returns false for OpenAI-compatible backend with gpt in model name', () => {
        expect(生图接口支持NSFW({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'https://api.example.com',
            apiKey: 'key',
            model: 'gpt-image-1',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'openai',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'openai_images',
            图片接口路径: '/v1/images/generations',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: false
        })).toBe(false);
    });
});

describe('接口配置是否可用', () => {
    it('returns false for null', () => {
        expect(接口配置是否可用(null)).toBe(false);
    });

    it('returns true for valid SD WebUI config', () => {
        expect(接口配置是否可用({
            id: 'test',
            名称: 'test',
            供应商: 'openai_compatible',
            协议覆盖: 'auto',
            baseUrl: 'http://localhost:7860',
            apiKey: '',
            model: '',
            maxTokens: 0,
            temperature: 0,
            图片后端类型: 'sd_webui',
            图片接口路径模式: 'preset',
            图片预设接口路径: 'sd_txt2img',
            图片接口路径: '/sdapi/v1/txt2img',
            图片响应格式: 'url',
            图片走OpenAI自定义格式: false,
            NPC生图使用词组转化器: true
        })).toBe(true);
    });
});

describe('获取NSFW文生图接口配置', () => {
    it('returns null when image generation is disabled', () => {
        const settings = 构建测试接口设置({ 文生图功能启用: false });
        expect(获取NSFW文生图接口配置(settings)).toBeNull();
    });

    it('returns null when main config is null', () => {
        const settings = 创建空接口设置();
        expect(获取NSFW文生图接口配置(settings)).toBeNull();
    });

    it('keeps independent ComfyUI NSFW config usable when only the image backend is configured', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'https://main-8188.cnb.run',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'https://nsfw-8188.cnb.run'
        });
        settings.configs = [];
        settings.activeConfigId = '';

        const result = 获取NSFW文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://nsfw-8188.cnb.run');
        expect(result?.图片后端类型).toBe('comfyui');
        expect(接口配置是否可用(result)).toBe(true);
    });

    it('returns shared config when main backend supports NSFW and independent is off', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: false
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('sd_webui');
    });

    it('uses independent NSFW config when enabled', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'http://localhost:8188'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.baseUrl).toBe('http://localhost:8188');
    });

    it('falls back to main config when independent NSFW has no model for openai backend', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'novelai',
            NSFW生图模型使用模型: ''
        });
        const result = 获取NSFW文生图接口配置(settings);
        // When independent NSFW needs a model but none is provided, it falls back
        expect(result).not.toBeNull();
    });

    it('tries fallback when main backend does not support NSFW', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false
        });
        const result = 获取NSFW文生图接口配置(settings);
        // OpenAI doesn't support NSFW, so it tries fallbacks
        // Without scene config or discovered backends, this returns null
        expect(result).toBeNull();
    });

    it('tries discovered ComfyUI backends as last resort', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false
        });
        const discovered = [{ url: 'http://localhost:8188' }];
        const result = 获取NSFW文生图接口配置(settings, discovered);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.baseUrl).toBe('http://localhost:8188');
    });

    it('builds customer-facing ComfyUI auto switch config from reported backend', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'http://offline-comfyui:8188',
            ComfyUI工作流JSON: '{"1":{"class_type":"KSampler"}}'
        });
        const current = 获取文生图接口配置(settings);
        expect(current).not.toBeNull();
        const result = 用已发现ComfyUI后端替换地址(current!, { url: 'http://online-comfyui:8188/' });
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.baseUrl).toBe('http://online-comfyui:8188');
        expect(result?.图片接口路径).toBe('/prompt');
        expect(result?.ComfyUI工作流JSON).toBe(current?.ComfyUI工作流JSON);
        expect(result?.自动切换提示).toContain('已自动切换到在线 ComfyUI 后端');
    });

    it('prefers selected discovered ComfyUI URL over stale saved main URL', async () => {
        await 模拟已发现ComfyUI后端([
            { id: 'backend-old', url: 'https://old-8188.cnb.run', lastHeartbeatAt: '2026-05-13T16:00:00.000Z' },
            { id: 'backend-new', url: 'https://new-8188.cnb.run/', lastHeartbeatAt: '2026-05-13T17:00:00.000Z' }
        ]);
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'https://old-8188.cnb.run'
        });
        settings.功能模型占位.当前图片后端发现ID = 'backend-new';

        const result = 获取文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://new-8188.cnb.run');
    });

    it('prefers selected discovered ComfyUI URL for independent scene image config', async () => {
        await 模拟已发现ComfyUI后端([
            { id: 'scene-new', url: 'https://scene-new-8188.cnb.run/', lastHeartbeatAt: '2026-05-13T17:00:00.000Z' }
        ]);
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'https://main-old-8188.cnb.run',
            场景生图独立接口启用: true,
            场景生图后端类型: 'comfyui'
        });
        settings.功能模型占位.当前场景图片后端发现ID = 'scene-new';
        settings.功能模型占位.场景生图模型API地址 = 'https://scene-old-8188.cnb.run';

        const result = 获取场景文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://scene-new-8188.cnb.run');
    });

    it('prefers selected discovered ComfyUI URL for independent NSFW image config', async () => {
        await 模拟已发现ComfyUI后端([
            { id: 'nsfw-new', url: 'https://nsfw-new-8188.cnb.run/', lastHeartbeatAt: '2026-05-13T17:00:00.000Z' }
        ]);
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'https://nsfw-old-8188.cnb.run'
        });
        settings.功能模型占位.当前NSFW图片后端发现ID = 'nsfw-new';

        const result = 获取NSFW文生图接口配置(settings);

        expect(result?.baseUrl).toBe('https://nsfw-new-8188.cnb.run');
    });

    it('uses scene config as fallback for NSFW when scene backend supports it', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false,
            场景生图独立接口启用: true,
            场景生图后端类型: 'comfyui'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
    });

    it('builds correct endpoint for ComfyUI NSFW config (different backend from shared)', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'http://nsfw-comfyui:8188'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('comfyui');
        expect(result?.图片接口路径).toBe('/prompt');
    });

    it('builds correct endpoint for SD WebUI NSFW config (different backend from shared)', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'comfyui',
            文生图模型API地址: 'http://localhost:8188',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'sd_webui',
            NSFW生图模型API地址: 'http://nsfw-sd:7860'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('sd_webui');
        expect(result?.图片接口路径).toBe('/sdapi/v1/txt2img');
    });

    it('builds correct endpoint for NovelAI NSFW config (different backend from shared)', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'novelai',
            NSFW生图模型使用模型: 'nai-diffusion-4',
            NSFW生图模型API地址: 'https://image.novelai.net'
        });
        const result = 获取NSFW文生图接口配置(settings);
        expect(result).not.toBeNull();
        expect(result?.图片后端类型).toBe('novelai');
        expect(result?.图片接口路径).toBe('/ai/generate-image');
    });
});

describe('NSFW prompt generation', () => {
    it('构建运行时额外提示词 returns NSFW prompt when enabled', () => {
        const result = 构建运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toContain('NSFW');
        expect(result).toContain('肉棒');
        expect(result).toContain('小穴');
    });

    it('构建运行时额外提示词 returns empty when NSFW disabled', () => {
        const result = 构建运行时额外提示词('', { 启用NSFW模式: false });
        expect(result).toBe('');
    });

    it('构建运行时额外提示词 combines custom prompt with NSFW', () => {
        const result = 构建运行时额外提示词('custom instruction', { 启用NSFW模式: true });
        expect(result).toContain('custom instruction');
        expect(result).toContain('NSFW');
    });

    it('构建运行时额外提示词 returns only custom prompt when NSFW disabled', () => {
        const result = 构建运行时额外提示词('custom instruction', { 启用NSFW模式: false });
        expect(result).toBe('custom instruction');
        expect(result).not.toContain('NSFW');
    });

    it('构建文生图运行时额外提示词 returns image NSFW prompt when enabled', () => {
        const result = 构建文生图运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toContain('NSFW');
        expect(result).toContain('adult');
        expect(result).toContain('sensual body language');
    });

    it('构建文生图运行时额外提示词 returns empty when NSFW disabled', () => {
        const result = 构建文生图运行时额外提示词('', { 启用NSFW模式: false });
        expect(result).toBe('');
    });

    it('构建文生图运行时额外提示词 combines custom prompt with image NSFW', () => {
        const result = 构建文生图运行时额外提示词('style: dark fantasy', { 启用NSFW模式: true });
        expect(result).toContain('style: dark fantasy');
        expect(result).toContain('NSFW');
        expect(result).toContain('adult');
    });

    it('构建运行时额外提示词 handles undefined options gracefully', () => {
        const result = 构建运行时额外提示词('test', undefined);
        expect(result).toBe('test');
    });

    it('构建文生图运行时额外提示词 handles undefined options gracefully', () => {
        const result = 构建文生图运行时额外提示词('test', undefined);
        expect(result).toBe('test');
    });

    it('构建运行时额外提示词 trims whitespace', () => {
        const result = 构建运行时额外提示词('  custom  ', { 启用NSFW模式: true });
        expect(result.startsWith('custom')).toBe(true);
        expect(result).toContain('NSFW');
    });

    it('构建运行时额外提示词 handles empty custom prompt', () => {
        const result = 构建运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toBe(默认NSFW模式提示词);
    });

    it('构建文生图运行时额外提示词 handles empty custom prompt', () => {
        const result = 构建文生图运行时额外提示词('', { 启用NSFW模式: true });
        expect(result).toBe(默认文生图NSFW模式提示词);
    });
});

describe('NSFW end-to-end flow simulation', () => {
    it('full flow: SD WebUI independent NSFW with ComfyUI fallback', () => {
        // Step 1: User enables independent NSFW with ComfyUI backend
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'comfyui',
            NSFW生图模型API地址: 'http://nsfw-comfyui:8188',
            NSFWComfyUI工作流JSON: '{"1":{"class_type":"KSampler"}}'
        });

        // Step 2: Get NSFW config
        const nsfwConfig = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfig).not.toBeNull();

        // Step 3: Verify config is usable
        expect(接口配置是否可用(nsfwConfig)).toBe(true);

        // Step 4: Verify it supports NSFW
        expect(生图接口支持NSFW(nsfwConfig)).toBe(true);

        // Step 5: Verify backend type
        expect(nsfwConfig?.图片后端类型).toBe('comfyui');
        expect(nsfwConfig?.图片接口路径).toBe('/prompt');
    });

    it('full flow: OpenAI main with discovered ComfyUI fallback', () => {
        // Step 1: Main backend is OpenAI (doesn't support NSFW)
        const settings = 构建测试接口设置({
            文生图后端类型: 'openai',
            文生图模型使用模型: 'dall-e-3',
            文生图模型API地址: 'https://api.openai.com',
            NSFW生图独立接口启用: false
        });

        // Step 2: No NSFW config without discovered backends
        const nsfwConfigNoFallback = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfigNoFallback).toBeNull();

        // Step 3: With discovered ComfyUI backend, NSFW becomes available
        const nsfwConfig = 获取NSFW文生图接口配置(settings, [
            { url: 'http://comfyui.local:8188' }
        ]);
        expect(nsfwConfig).not.toBeNull();
        expect(nsfwConfig?.图片后端类型).toBe('comfyui');
        expect(生图接口支持NSFW(nsfwConfig)).toBe(true);
    });

    it('full flow: NSFW prompt injection into image generation', () => {
        // Step 1: User enables NSFW mode
        const gameConfig = { 启用NSFW模式: true };

        // Step 2: Build NSFW image prompt
        const imagePrompt = 构建文生图运行时额外提示词('', gameConfig);
        expect(imagePrompt).toContain('NSFW');
        expect(imagePrompt).toContain('adult');

        // Step 3: Build runtime prompt for story
        const storyPrompt = 构建运行时额外提示词('', gameConfig);
        expect(storyPrompt).toContain('NSFW');
        expect(storyPrompt).toContain('肉棒');

        // Step 4: Custom prompt gets merged
        const customExtra = 'additional style requirement';
        const mergedImagePrompt = 构建文生图运行时额外提示词(customExtra, gameConfig);
        expect(mergedImagePrompt).toContain(customExtra);
        expect(mergedImagePrompt).toContain('NSFW');
    });

    it('full flow: NSFW disabled returns empty prompts', () => {
        const gameConfig = { 启用NSFW模式: false };

        const imagePrompt = 构建文生图运行时额外提示词('', gameConfig);
        expect(imagePrompt).toBe('');

        const storyPrompt = 构建运行时额外提示词('', gameConfig);
        expect(storyPrompt).toBe('');
    });

    it('full flow: NovelAI independent NSFW config', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'novelai',
            NSFW生图模型使用模型: 'nai-diffusion-4',
            NSFW生图模型API地址: 'https://image.novelai.net',
            NSFW生图模型API密钥: 'test-token'
        });

        const nsfwConfig = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfig).not.toBeNull();
        expect(nsfwConfig?.图片后端类型).toBe('novelai');
        expect(nsfwConfig?.图片接口路径).toBe('/ai/generate-image');
        expect(nsfwConfig?.apiKey).toBe('test-token');
        expect(生图接口支持NSFW(nsfwConfig)).toBe(true);
    });

    it('full flow: SD WebUI independent NSFW reuses shared connection', () => {
        const settings = 构建测试接口设置({
            文生图后端类型: 'sd_webui',
            文生图模型API地址: 'http://localhost:7860',
            NSFW生图独立接口启用: true,
            NSFW生图后端类型: 'sd_webui',
            NSFW生图模型API地址: '',
            NSFW生图模型API密钥: ''
        });

        const nsfwConfig = 获取NSFW文生图接口配置(settings);
        expect(nsfwConfig).not.toBeNull();
        expect(nsfwConfig?.图片后端类型).toBe('sd_webui');
        // When NSFW URL is empty and backend matches shared, it reuses shared URL
        expect(nsfwConfig?.baseUrl).toBe('http://localhost:7860');
    });
});

# DeepSeek：

**原始回答**
这个测试文件逻辑上很严谨，但它更多是**对理想逻辑的“正向验证”**。如果前端出问题，问题大概率不在测试本身，而在被测试的实际函数（`获取NSFW文生图接口配置` 等）的实现，或者它们运行时读到的**真实配置数据**。

结合你之前的排查，NSFW 失败的根本原因可能是下面几种情况：

### 1. 测试能过，但代码在真实环境下的关键问题
- **从测试里可以看到，`获取NSFW文生图接口配置` 依赖 `设置.功能模型占位.当前NSFW图片后端发现ID` 来匹配已发现的后端。**
  如果你的前端没有正确持久化这个 `发现ID`，或者 CNB 注册中心返回的后端 `id` 和你保存的不一致，就会匹配失败，导致 NSFW 配置为空，从而使用不支持 NSFW 的主接口（比如 OpenAI）去生图，自然会失败。
- **测试中的 `NSFWComfyUI工作流JSON` 是手动传入的**。
  如果你的前端在保存设置时，没有把这个工作流 JSON 真正存进 `功能模型占位`，NSFW 请求体里就没有工作流，ComfyUI 无法执行。

### 2. ComfyUI 后端本身有变数
- 测试依赖 `生图接口支持NSFW` 判断后端是 `comfyui` 就返回 `true`。但如果 ComfyUI 后端因为缺 `onnxruntime`（就像你之前遇到的）实际跑不了 NSFW 模型，返回的图片可能空白或报错。**前端判断“支持”是真，但后端“能不能跑”是另一回事。**

### 3. 前端调用链可能没走到正确分支
- 测试中 `获取NSFW文生图接口配置` 有很多 fallback 逻辑（独立接口 -> 场景接口 -> 已发现后端）。
  如果调用方（比如发送生图请求的模块）没有实际调用这个函数，或者用了另一个获取配置的函数，NSFW 特性就根本没启用。

### 建议的排查方向
1. **检查真实保存的 NSFW 独立接口配置**：在浏览器控制台打印出当前的 `接口设置结构`，重点看 `NSFW生图独立接口启用`、`NSFWComfyUI工作流JSON` 是否和你 UI 上设置的一致。
2. **检查已发现后端匹配**：打印 `已发现ComfyUI后端缓存` 和 `功能模型占位.当前NSFW图片后端发现ID`，确认它们能对应。
3. **打日志确认函数调用**：在 `获取NSFW文生图接口配置` 的返回处加 `console.log`，看实际返回的配置是不是 `null`，以及当时的主接口和独立接口设置是什么。

如果需要，我可以帮你写一段在控制台运行的诊断脚本，直接把这些关键配置打印出来。

