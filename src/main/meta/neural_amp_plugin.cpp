/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of jea-plugins-neural-amp-plugin
 * Created on: 25 нояб. 2020 г.
 *
 * jea-plugins-neural-amp-plugin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * jea-plugins-neural-amp-plugin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with jea-plugins-neural-amp-plugin. If not, see <https://www.gnu.org/licenses/>.
 */

#include <lsp-plug.in/plug-fw/meta/ports.h>
#include <lsp-plug.in/shared/meta/developers.h>
#include <private/meta/neural_amp_plugin.h>

#define JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION_MAJOR       1
#define JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION_MINOR       0
#define JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION_MICRO       0

#define JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION  \
    LSP_MODULE_VERSION( \
        JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION_MAJOR, \
        JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION_MINOR, \
        JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION_MICRO  \
    )

namespace lsp
{
    namespace meta
    {
        //-------------------------------------------------------------------------
        // Plugin metadata

        // NOTE: Port identifiers should not be longer than 7 characters as it will overflow VST2 parameter name buffers
        static const port_t neural_amp_plugin_mono_ports[] =
        {
            // Input and output audio ports
            PORTS_MONO_PLUGIN,

            // Input controls
            BYPASS,
            INT_CONTROL("d_in", "Delay in samples", U_SAMPLES, neural_amp_plugin::SAMPLES),
            DRY_GAIN(0.0f),
            WET_GAIN(1.0f),
            OUT_GAIN,

            // Output controls
            METER_MINMAX("d_out", "Delay time in milliseconds", U_MSEC, 0.0f, neural_amp_plugin::DELAY_OUT_MAX_TIME),
            METER_GAIN("min", "Input gain", GAIN_AMP_P_48_DB),
            METER_GAIN("mout", "Output gain", GAIN_AMP_P_48_DB),

            PORTS_END
        };

        // NOTE: Port identifiers should not be longer than 7 characters as it will overflow VST2 parameter name buffers
        static const port_t neural_amp_plugin_stereo_ports[] =
        {
            // Input and output audio ports
            PORTS_STEREO_PLUGIN,

            // Input controls
            BYPASS,
            INT_CONTROL("d_in", "Delay in samples", U_SAMPLES, neural_amp_plugin::SAMPLES),
            DRY_GAIN(0.0f),
            WET_GAIN(1.0f),
            OUT_GAIN,

            // Output controls
            METER_MINMAX("d_out", "Delay time in milliseconds", U_MSEC, 0.0f, neural_amp_plugin::DELAY_OUT_MAX_TIME),
            METER_GAIN("min_l", "Input gain left",  GAIN_AMP_P_48_DB),
            METER_GAIN("mout_l", "Output gain left",  GAIN_AMP_P_48_DB),
            METER_GAIN("min_r", "Input gain right",  GAIN_AMP_P_48_DB),
            METER_GAIN("mout_r", "Output gain right", GAIN_AMP_P_48_DB),

            PORTS_END
        };

        static const int plugin_classes[]       = { C_DELAY, -1 };
        static const int clap_features_mono[]   = { CF_AUDIO_EFFECT, CF_UTILITY, CF_MONO, -1 };
        static const int clap_features_stereo[] = { CF_AUDIO_EFFECT, CF_UTILITY, CF_STEREO, -1 };

        const meta::bundle_t neural_amp_plugin_bundle =
        {
            "neural_amp_plugin",
            "Plugin Template",
            B_UTILITIES,
            "", // TODO: provide ID of the video on YouTube
            "" // TODO: write plugin description, should be the same to the english version in 'bundles.json'
        };

        const plugin_t neural_amp_plugin_mono =
        {
            "Pluginschablone Mono",
            "Plugin Template Mono",
            "PS1M",
            &developers::v_sadovnikov,
            "neural_amp_plugin_mono",
            LSP_LV2_URI("neural_amp_plugin_mono"),
            LSP_LV2UI_URI("neural_amp_plugin_mono"),
            "xxxx",         // TODO: fill valid VST2 ID (4 letters/digits)
            1,              // TODO: fill valid LADSPA identifier (positive decimal integer)
            LSP_LADSPA_URI("neural_amp_plugin_mono"),
            LSP_CLAP_URI("neural_amp_plugin_mono"),
            JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION,
            plugin_classes,
            clap_features_mono,
            E_DUMP_STATE,
            neural_amp_plugin_mono_ports,
            "template/plugin.xml",
            NULL,
            mono_plugin_port_groups,
            &neural_amp_plugin_bundle
        };

        const plugin_t neural_amp_plugin_stereo =
        {
            "Pluginschablone Stereo",
            "Plugin Template Stereo",
            "PS1S",
            &developers::v_sadovnikov,
            "neural_amp_plugin_stereo",
            LSP_LV2_URI("neural_amp_plugin_stereo"),
            LSP_LV2UI_URI("neural_amp_plugin_stereo"),
            "yyyy",         // TODO: fill valid VST2 ID (4 letters/digits)
            2,              // TODO: fill valid LADSPA identifier (positive decimal integer)
            LSP_LADSPA_URI("neural_amp_plugin_stereo"),
            LSP_CLAP_URI("neural_amp_plugin_stereo"),
            JEA_PLUGINS_NEURAL_AMP_PLUGIN_VERSION,
            plugin_classes,
            clap_features_stereo,
            E_DUMP_STATE,
            neural_amp_plugin_stereo_ports,
            "template/plugin.xml",
            NULL,
            stereo_plugin_port_groups,
            &neural_amp_plugin_bundle
        };
    } /* namespace meta */
} /* namespace lsp */



