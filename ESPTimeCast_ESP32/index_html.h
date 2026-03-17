#pragma once
const char index_html[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <meta
      http-equiv="Cache-Control"
      content="no-cache, no-store, must-revalidate"
    />
    <meta http-equiv="Pragma" content="no-cache" />
    <meta http-equiv="Expires" content="0" />
    <title>ESPTimeCast Settings</title>
    <style>
      :root {
        --accent-color: #f97316;
        --accent-hover: #ea580c;
        --bg-color: #f5f5f5;
        --card-bg: #ffffff;
        --text-color: #1a1a1a;
        --text-muted: #555555;
        --border-color: #d4d4d4;
        --section-border: #f97316;
      }

      .ssid-wrapper {
        position: relative;
      }

      .combo-container {
        display: flex;
        box-sizing: border-box;
        width: 100%;
        border: 1px solid var(--border-color);
        border-radius: 0;
        background-color: #ffffff;
        color: var(--text-color);
        font-size: 1rem;
        appearance: none;
      }

      #ssid {
        border-radius: 0;
        flex: 1;
        border: none;
        outline: none;
        background: transparent;
        color: var(--text-color);
      }

      .icon-btn {
        width: 40px;
        border: none;
        background: none;
        cursor: pointer;
        display: flex;
        align-items: center;
        justify-content: center;
        color: #666;
        transition: background 0.2s;
      }

      #arrowBtn {
        background: transparent;
        border: none;
        width: 40px;
        border-left: 1px solid var(--border-color);
      }

      #arrowBtn>svg {
        position: relative;
        top: 2px;
        filter: none;
        opacity: 1;
      }

      #arrowBtn path[style*="fill: #fff"] {
        fill: var(--text-color) !important;
      }

      #arrowBtn:disabled>svg {
        position: relative;
        top: 2px;
        opacity: 0.25;
      }

      #arrowBtn:hover {
        transform: translateY(-1px);
        background: #f5f5f5;
      }

      #arrowBtn:disabled:hover {
        transform: translateY(0px);
        background: none;
      }

      #arrowBtn:disabled {
        cursor: not-allowed;
        background: none;
        color: rgba(0, 0, 0, 0.25);
      }

      #scanBtn {
        border-radius: 0;
        width: 75px;
        padding: 0;
        text-align: center;
        align-self: auto;
      }

      .icon-btn:hover {
        background: #f5f5f5;
      }

      #scanBtn:disabled {
        background: rgba(249, 115, 22, 0.5);
        cursor: wait;
      }

      #ssidList {
        position: absolute;
        width: 100%;
        max-height: 50vh;
        overflow-y: auto;
        background: white;
        border: 1px solid var(--border-color);
        border-radius: 0;
        display: none;
        z-index: 1000;
        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
      }

      .ssid-option {
        padding: 10px 12px;
        cursor: pointer;
        color: black;
      }

      .ssid-option:hover {
        background-color: var(--accent-color);
        color: white;
      }

      * {
        box-sizing: border-box;
      }

      html {
        background: var(--bg-color);
        height: 100%;
      }

      body {
        font-family: -apple-system, system-ui, "Segoe UI", Roboto, sans-serif;
        margin: 0;
        padding: 2rem 1rem;
        color: var(--text-color);
        opacity: 0;
        transition: opacity 0.4s ease;
        visibility: hidden;
        height: 100%;
        line-height: 1.5;
        -webkit-font-smoothing: antialiased;
        -moz-osx-font-smoothing: grayscale;
      }

      body.loaded {
        visibility: visible;
        opacity: 1;
      }

      body.modal-open {
        overflow: hidden;
      }

      h1 {
        text-align: center;
        font-size: 1.5rem;
        margin-bottom: 1.5rem;
        color: var(--text-color);
      }

      h2 {
        margin-top: 2.5rem;
        margin-bottom: 0.5rem;
        font-size: 0.85rem;
        font-weight: 700;
        text-transform: uppercase;
        letter-spacing: 0.08em;
        color: var(--text-color);
        padding-left: 0.75rem;
        border-left: 4px solid var(--section-border);
      }

      h3 {
        font-weight: normal;
        font-size: 1.35rem;
        margin: 0.5rem 0 0 0;
      }

      #savingModalContent p {
        line-height: 1.6rem;
      }

      .modal-buttons {
        display: flex;
        justify-content: center;
        gap: 1rem;
      }

      form:first-of-type>h2:first-of-type {
        margin-top: 1.5rem;
      }

      .logo {
        display: flex;
        justify-content: center;
        align-items: center;
        padding: 1rem 0;
      }

      .logo-text {
        font-size: 1.6rem;
        font-weight: 800;
        letter-spacing: 0.05em;
        color: var(--accent-color);
        text-transform: uppercase;
      }

      form {
        background: var(--card-bg);
        border: 1px solid var(--border-color);
        display: flex;
        flex-direction: column;
        max-width: 900px;
        margin: 0 auto;
        padding: 1.5rem 1.5rem 2.5rem 1.5rem;
        border-radius: 0;
      }

      label {
        font-size: 0.9rem;
        display: block;
        margin-top: 0.75rem;
        color: var(--text-color);
      }

      input[type="text"],
      input[type="time"],
      input[type="password"],
      input[type="date"],
      input[type="number"],
      select {
        width: 100%;
        padding: 0.75rem;
        border: 1px solid var(--border-color);
        border-radius: 0;
        background-color: #ffffff;
        color: var(--text-color);
        font-size: 1rem;
        appearance: none;
      }

      input[type="time"]:disabled,
      input[type="text"]:disabled,
      input[type="number"]:disabled,
      input[type="date"]:disabled {
        color: rgba(0, 0, 0, 0.25);
        background-color: #fafafa;
      }

      input[type="submit"] {
        background-color: var(--accent-color);
        color: white;
        font-size: 1rem;
        border: none;
        border-radius: 0;
        cursor: pointer;
        transition: background-color 0.2s ease-in-out;
        padding: 0.9rem 1.8rem;
        font-weight: 600;
        text-transform: uppercase;
        letter-spacing: 0.05em;
      }

      input[type="submit"]:hover {
        background-color: var(--accent-hover);
      }

      input[type="time"]::-webkit-calendar-picker-indicator,
      input[type="date"]::-webkit-calendar-picker-indicator {
        filter: none;
      }

      .toggle-switch input[type="checkbox"]:checked+.toggle-slider {
        background-color: var(--accent-color);
      }

      .toggle-switch input[type="checkbox"]:disabled+.toggle-slider::before {
        background-color: rgba(204, 204, 204, 0.5);
      }

      input:-webkit-autofill,
      input:-webkit-autofill:hover,
      input:-webkit-autofill:focus,
      input:-webkit-autofill:active {
        -webkit-text-fill-color: var(--text-color) !important;
        -webkit-box-shadow: 0 0 0px 1000px #ffffff inset !important;
        box-shadow: 0 0 0px 1000px #ffffff inset !important;
        transition: background-color 5000000s ease-in-out 0s, color 5000000s ease-in-out 0s;
        caret-color: var(--text-color);
      }

      input::placeholder,
      textarea::placeholder {
        color: #999999;
        opacity: 1;
      }

      .form-row {
        display: flex;
        flex-direction: column;
      }

      .form-row.two-col {
        flex-direction: column;
      }

      .form-row.two-col>div {
        flex: 1;
      }

      .primary-button {
        background: var(--accent-color);
        color: white;
        padding: 0.9rem 1.8rem;
        font-size: 1rem;
        font-weight: 600;
        border: none;
        border-radius: 0;
        cursor: pointer;
        text-align: center;
        align-self: center;
        width: fit-content;
        transition: background 0.2s ease-in-out;
      }

      .primary-button:hover {
        background-color: var(--accent-hover);
      }

      .primary-button:active {
        transform: scale(0.97);
      }

      #customMessage {
        text-transform: uppercase;
      }

      .note {
        font-size: 0.85rem;
        text-align: center;
        margin-top: 1rem;
      }

      #savingModal {
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        display: none;
        justify-content: center;
        align-items: center;
        z-index: 1000;
        background: rgba(0, 0, 0, 0.45);
        transition: opacity 0.3s ease;
      }

      #savingModalContent {
        background: #ffffff;
        border-radius: 0;
        box-shadow: 0 4px 16px rgba(0, 0, 0, 0.15);
        margin: 1.5rem;
        padding: 2rem 2.5rem;
        text-align: center;
        border: none;
        border-top: 4px solid var(--accent-color);
        color: var(--text-color);
      }

      .spinner {
        border: 4px solid #e5e5e5;
        border-top: 4px solid var(--accent-color);
        border-radius: 50%;
        width: 36px;
        height: 36px;
        animation: spin 1s linear infinite;
        margin: 0 auto 1rem;
      }

      .footer {
        font-size: 0.8rem;
        text-align: center;
        margin-top: 1.5rem;
        color: var(--text-muted);
      }

      a {
        color: var(--accent-color);
      }

      a:hover {
        color: var(--accent-hover);
      }

      .small {
        display: block;
        font-size: 0.8rem;
        margin-top: 0.25rem;
        color: var(--text-muted);
      }

      select option {
        color: black;
      }

      .geo-disabled {
        opacity: 0.5;
        background: none !important;
        color: var(--text-color) !important;
        border: 1px solid var(--border-color);
        cursor: not-allowed;
      }

      .geo-disabled:hover {
        transform: none;
        box-shadow: none;
        background-color: none;
        background: none;
      }

      .button-row {
        display: flex;
        margin-top: 0.5rem;
        gap: 1rem;
        justify-content: space-evenly;
        flex-direction: column;
      }

      @keyframes spin {
        0% {
          transform: rotate(0deg);
        }

        100% {
          transform: rotate(360deg);
        }
      }

      #openWeatherCountry {
        margin-top: 0.75rem;
      }

      @media (min-width: 361px) {
        .form-row.two-col {
          flex-direction: row;
          gap: 1rem;
        }

        .button-row {
          flex-direction: row;
          gap: 0;
        }

        #openWeatherCountry {
          margin-top: 0;
        }
      }

      .toggle-switch {
        display: inline-flex;
        align-items: center;
        gap: 10px;
        cursor: pointer;
        position: relative;
      }

      .toggle-switch input {
        opacity: 0;
        width: 0;
        height: 0;
        position: absolute;
      }

      .toggle-slider {
        position: relative;
        width: 48px;
        height: 24px;
        border-radius: 0;
        transition: all 0.18s ease;
        background: #cccccc;
        border: 1px solid var(--border-color);
      }

      .toggle-slider::before {
        content: "";
        position: absolute;
        height: 18px;
        width: 18px;
        left: 2px;
        top: 2px;
        border-radius: 0;
        background: #ffffff;
        transition: all 0.18s ease;
        box-shadow: 0 1px 3px rgba(0, 0, 0, 0.2);
      }

      .toggle-switch input:checked+.toggle-slider {
        background: var(--accent-color);
        border-color: var(--accent-color);
      }

      .toggle-switch input:checked+.toggle-slider::before {
        transform: translateX(24px);
      }

      .toggle-switch input:disabled+.toggle-slider {
        opacity: 0.4;
        cursor: not-allowed;
      }

      .accent {
        accent-color: var(--accent-color);
      }

      .collapsible-toggle {
        display: flex;
        align-items: center;
        cursor: pointer;
        font-size: 0.85rem;
        font-weight: 700;
        background: none;
        border: none;
        color: var(--text-color);
        padding: 0;
        margin: 0;
        outline: none;
        gap: 0.5em;
        user-select: none;
        margin-top: 3rem;
        text-transform: uppercase;
        letter-spacing: 0.08em;
        padding-left: 0.75rem;
        border-left: 4px solid var(--accent-color);
      }

      #configForm>button.collapsible-toggle>span:nth-child(2) {
        border-bottom: solid 1px var(--text-color);
      }

      .collapsible-toggle .icon-area {
        transition: transform 0.3s ease;
        display: flex;
        color: var(--accent-color);
      }

      .collapsible-toggle.open .icon-area {
        transform: rotate(90deg);
      }

      .collapsible-content {
        overflow: hidden;
        height: none;
        transition: height 0.3s ease;
        color: var(--text-color);
        margin-bottom: 3rem;
      }

      .collapsible-content-inner {
        padding: 1em 0;
      }

      input[type="range"] {
        -webkit-appearance: none;
        width: 100%;
        height: 6px;
        background: transparent;
        cursor: pointer;
      }

      input[type="range"]::-webkit-slider-runnable-track {
        height: 6px;
        background: #d4d4d4;
        border-radius: 0;
      }

      input[type="range"]::-webkit-slider-thumb {
        -webkit-appearance: none;
        width: 18px;
        height: 18px;
        border-radius: 0;
        background: var(--accent-color);
        border: none;
        margin-top: -6px;
        box-shadow: none;
        transition: transform 0.15s ease;
      }

      input[type="range"]:hover::-webkit-slider-thumb {
        transform: scale(1.1);
      }

      input[type="range"]::-moz-range-track {
        height: 6px;
        background: #d4d4d4;
        border-radius: 0;
      }

      input[type="range"]::-moz-range-thumb {
        width: 18px;
        height: 18px;
        border-radius: 0;
        background: var(--accent-color);
        border: none;
        box-shadow: none;
      }

      input[type="range"]:disabled {
        cursor: not-allowed;
        opacity: 0.6;
      }

      input[type="range"]:disabled::-webkit-slider-runnable-track {
        background: #e5e5e5;
      }

      input[type="range"]:disabled::-moz-range-track {
        background: #e5e5e5;
      }

      input[type="range"]:disabled::-webkit-slider-thumb {
        background: #999;
        box-shadow: none;
        transform: none;
      }

      input[type="range"]:disabled::-moz-range-thumb {
        background: #999;
        box-shadow: none;
      }

      .sub-collapsible {
        color: var(--text-color);
        width: fit-content;
        background: none;
        border: none;
        display: flex;
        justify-content: space-between;
        align-items: center;
        padding: 1.5rem 1.5rem 1rem 2rem;
        font-weight: 600;
        letter-spacing: 0.08em;
        text-transform: uppercase;
        opacity: 0.55;
        cursor: pointer;
        font-size: 0.9rem;
      }

      .sub-collapsible.open {
        opacity: 1;
      }

      .sub-collapsible-content {
        overflow: hidden;
        height: 0;
        transition: height 0.3s ease;
      }

      .sub-collapsible-content .content-wrapper {
        border-radius: 0;
        padding: 1rem 2rem 2rem 2rem;
        background: #fafafa;
        margin-bottom: 2rem;
        border: 1px solid var(--border-color);
      }

      .sub-collapsible[aria-expanded="true"]+.sub-collapsible-content {
        display: block;
      }

      .sub-collapsible::after {
        padding-bottom: 0.2rem;
        padding-left: 0.4rem;
        line-height: 0;
        font-size: 1.1rem;
        content: ">";
        transition: transform 0.25s ease;
        color: var(--accent-color);
      }

      .sub-collapsible.open::after {
        transform: translateY(-0.1rem) rotate(90deg);
        opacity: 1;
      }

      .content-wrapper>label:nth-child(1) {
        margin-top: 0;
      }

      .content-wrapper>.toggle-padding>label:nth-child(1),
      .content-wrapper>.form-group:nth-child(1)>label:nth-child(1) {
        margin-top: 0.75rem;
      }

      #autoDimmingNote {
        opacity: 0.5;
        text-align: unset;
        position: absolute;
        padding-right: 3rem;
        top: 0.9rem;
      }

      .content-wrapper .small {
        text-align: center;
        opacity: 0.75;
      }

      .toggle-row {
        display: flex;
        align-items: center;
        justify-content: space-between;
      }

      .toggle-row-lg {
        display: flex;
        align-items: center;
        justify-content: space-between;
        margin-top: 1.75rem;
      }

      .toggle-row-sm {
        display: flex;
        align-items: center;
        justify-content: space-between;
        margin-top: 0.75rem;
      }

      .label-text {
        margin-right: 0.5em;
      }

      .range-full {
        width: 100%;
      }

      .mt-lg {
        margin-top: 1.75rem;
      }

      #configForm>div.collapsible-content>div:nth-child(2)>div>div {
        margin-top: 2rem;
      }

      #configForm>div.collapsible-content>div:nth-child(8)>div>div.toggle-padding>div:nth-child(1)>label {
        margin-top: 0.75rem;
      }

      #configForm>div.collapsible-content>div:nth-child(6)>div>div.toggle-padding>label:nth-child(4) {
        position: relative;
      }

      #geo-button,
      .primary-button.cmsg1,
      .primary-button.cmsg2 {
        background-color: #ffffff;
        color: var(--text-color);
        font-weight: normal;
        font-size: 0.75rem;
        border: 1px solid var(--border-color);
      }

      #geo-button:hover,
      .primary-button.cmsg1:hover {
        background-color: var(--accent-color);
        color: white;
        border-color: var(--accent-color);
      }

      .primary-button.cmsg2:hover {
        background-color: #dc2626;
        color: white;
        border-color: #dc2626;
      }

      .device-info {
        margin-top: 0.75rem;
      }

      hr {
        margin: 1.5rem 0;
        border: 0;
        border-top: 1px solid var(--border-color);
      }

      #hostnameInput {
        min-width: calc(3ch + 1rem);
        text-align: center;
        padding: 0.5rem;
      }

      /* ------------------------------------------------------------------
         Full-width desktop control surface
         ------------------------------------------------------------------ */

      body {
        margin: 0;
        padding: 0;
        background: #f3efe8;
        color: var(--text-color);
      }

      #configForm {
        width: 100%;
        max-width: none;
        margin: 0;
        padding: 0;
        border: none;
        background: transparent;
      }

      .app-shell {
        min-height: 100vh;
        padding: 1rem;
        display: grid;
        gap: 0.9rem;
      }

      .shell-header {
        position: fixed;
        top: 0.9rem;
        left: 0.9rem;
        z-index: 40;
        padding: 0;
        background: transparent;
        border: none;
      }

      .shell-copy,
      .panel-copy {
        margin: 0;
        color: var(--text-muted);
        font-size: 0.9rem;
      }

      .shell-toolbar {
        display: block;
      }

      .save-button {
        display: inline-flex;
        align-items: center;
        justify-content: center;
        gap: 0;
        width: 42px;
        min-width: 42px;
        min-height: 42px;
        padding: 0.6rem;
        overflow: hidden;
        white-space: nowrap;
        font-size: 0.84rem;
        transition: width 0.18s ease, gap 0.18s ease, padding 0.18s ease,
          background-color 0.18s ease;
      }

      .save-button .save-icon {
        width: 14px;
        height: 14px;
        flex: 0 0 auto;
      }

      .save-button .save-label {
        max-width: 0;
        opacity: 0;
        overflow: hidden;
        transition: max-width 0.18s ease, opacity 0.18s ease;
      }

      .save-button:hover,
      .save-button:focus-visible {
        width: 124px;
        gap: 0.5rem;
        padding: 0.6rem 0.9rem;
      }

      .save-button:hover .save-label,
      .save-button:focus-visible .save-label {
        max-width: 72px;
        opacity: 1;
      }

      .banner-note {
        border: 1px solid #fdba74;
        background: #fff7ed;
        color: #9a3412;
        padding: 0.9rem 1rem;
        font-size: 0.86rem;
      }

      .workspace-grid {
        display: grid;
        gap: 0.9rem;
      }

      .workspace-pane {
        display: grid;
        gap: 0.9rem;
        align-content: start;
      }

      .panel {
        display: grid;
        gap: 0.75rem;
        align-content: start;
        padding: 0.95rem 1rem;
        border: 1px solid var(--border-color);
        background: #ffffff;
      }

      .panel-header {
        display: grid;
        gap: 0.2rem;
      }

      .panel h2 {
        margin: 0;
        padding: 0;
        border: none;
        font-size: 1rem;
        font-weight: 700;
        letter-spacing: 0.01em;
        text-transform: none;
        color: var(--text-color);
      }

      .panel label {
        margin-top: 0.2rem;
        font-size: 0.73rem;
        font-weight: 700;
        text-transform: uppercase;
        letter-spacing: 0.08em;
        color: #57534e;
      }

      .panel input[type="text"],
      .panel input[type="time"],
      .panel input[type="password"],
      .panel input[type="date"],
      .panel input[type="number"],
      .panel select {
        margin-top: 0.3rem;
        padding: 0.72rem 0.78rem;
        font-size: 0.96rem;
        border: 1px solid #d6d3d1;
        background: #fff;
      }

      .panel input[type="submit"],
      .panel button,
      .shell-header button {
        min-height: 44px;
      }

      .form-row.two-col {
        display: grid;
        grid-template-columns: 1fr;
        gap: 0.7rem;
      }

      .field-grid {
        display: grid;
        gap: 0.7rem;
      }

      .inline-note {
        margin-top: -0.1rem;
      }

      .small {
        margin-top: 0.2rem;
        text-align: left;
        color: var(--text-muted);
      }

      .panel-actions,
      .button-row,
      .ota-stack {
        display: grid;
        gap: 0.6rem;
      }

      .button-row {
        margin-top: 0;
      }

      .button-row .primary-button,
      .panel-actions .primary-button,
      .ota-stack .primary-button,
      #scanBtn,
      #geo-button {
        width: 100%;
        align-self: stretch;
      }

      .combo-container {
        align-items: stretch;
        min-height: 44px;
      }

      #scanBtn {
        width: 92px;
        font-size: 0.84rem;
      }

      #ssid {
        min-width: 0;
      }

      .toggle-padding,
      .device-info {
        display: grid;
        gap: 0.65rem;
      }

      .toggle-row,
      .toggle-row-lg,
      .toggle-row-sm {
        display: grid;
        grid-template-columns: minmax(0, 1fr) auto;
        align-items: center;
        gap: 0.75rem;
        margin: 0;
      }

      .label-text {
        margin-right: 0;
        font-size: 0.86rem;
        font-weight: 600;
        letter-spacing: 0;
        text-transform: none;
        color: var(--text-color);
      }

      #autoDimmingNote {
        position: static;
        padding-right: 0;
        top: auto;
        grid-column: 1 / -1;
        margin-top: -0.25rem;
      }

      .panel-collapsible .sub-collapsible {
        width: 100%;
        padding: 0;
        background: none;
        color: var(--text-color);
        border: none;
        display: grid;
        grid-template-columns: minmax(0, 1fr) auto;
        align-items: center;
        gap: 0.75rem;
        font-size: 1rem;
        font-weight: 700;
        text-transform: none;
        letter-spacing: 0.01em;
        opacity: 1;
      }

      .panel-collapsible .sub-collapsible::after {
        content: "+";
        padding: 0;
        font-size: 1.2rem;
        line-height: 1;
        color: var(--accent-color);
        transform: none;
      }

      .panel-collapsible .sub-collapsible.open::after {
        content: "-";
        transform: none;
      }

      .panel-collapsible .sub-collapsible-content {
        height: 0;
        overflow: hidden;
        transition: height 0.24s ease;
      }

      .panel-collapsible .content-wrapper {
        margin-top: 0.8rem;
        padding: 0;
        border: none;
        background: transparent;
        display: grid;
        gap: 0.75rem;
      }

      .status-grid {
        display: grid;
        gap: 0.55rem;
      }

      .status-row {
        display: grid;
        grid-template-columns: minmax(0, 1fr) auto;
        gap: 0.8rem;
        align-items: center;
        padding-bottom: 0.45rem;
        border-bottom: 1px solid #ece7dd;
        font-size: 0.9rem;
      }

      .status-row:last-child {
        border-bottom: none;
        padding-bottom: 0;
      }

      .status-row strong,
      .status-row span:last-child {
        text-align: right;
      }

      .host-line {
        grid-template-columns: minmax(0, 1fr) minmax(0, auto);
      }

      .host-line span:last-child {
        display: inline-flex;
        align-items: center;
        gap: 0.3rem;
      }

      #hostnameInput {
        min-width: 8ch;
        width: 10ch;
        text-align: center;
        padding: 0.45rem 0.3rem;
        margin: 0;
      }

      @media (min-width: 720px) {
        .button-row,
        .panel-actions,
        .ota-stack {
          grid-template-columns: repeat(2, minmax(0, 1fr));
        }

        .form-row.two-col,
        .field-grid.two-col {
          grid-template-columns: repeat(2, minmax(0, 1fr));
        }

      }

      @media (min-width: 1180px) {
        .app-shell {
          min-height: 100vh;
          padding: 0.9rem;
          gap: 0.75rem;
        }

        .workspace-grid {
          grid-template-columns: 1.08fr 1fr 1fr;
          align-items: start;
        }

        .workspace-pane {
          overflow: visible;
          padding-right: 0;
        }

        .panel {
          gap: 0.65rem;
          padding: 0.85rem 0.9rem;
        }

        .wifi-panel-title {
          margin-top: 3rem !important;
        }

        .shell-copy {
          max-width: 52rem;
        }

        .panel-copy {
          font-size: 0.82rem;
        }

        .panel label {
          font-size: 0.68rem;
        }

        .panel input[type="text"],
        .panel input[type="time"],
        .panel input[type="password"],
        .panel input[type="date"],
        .panel input[type="number"],
        .panel select {
          padding: 0.62rem 0.7rem;
          font-size: 0.88rem;
        }

        .panel button,
        .panel input[type="submit"],
        .shell-header button {
          min-height: 40px;
        }

        .panel-collapsible .sub-collapsible {
          cursor: default;
          pointer-events: none;
        }

        .panel-collapsible .sub-collapsible::after {
          content: none;
        }

        .panel-collapsible .sub-collapsible-content {
          height: auto !important;
          overflow: visible;
        }
      }

      @media (hover: none), (pointer: coarse) {
        .shell-header {
          position: static;
          top: auto;
          left: auto;
        }

        .save-button {
          width: auto;
          gap: 0.5rem;
          padding: 0.6rem 0.9rem;
        }

        .save-button .save-label {
          max-width: 72px;
          opacity: 1;
        }
      }
    </style>
  </head>
  <body>
    <form id="configForm" onsubmit="submitConfig(event)">
      <div class="app-shell">
        <header class="shell-header">
          <div class="shell-toolbar">
            <button type="submit" class="primary-button save-button">
              <svg
                class="save-icon"
                viewBox="0 0 16 16"
                fill="none"
                xmlns="http://www.w3.org/2000/svg"
                aria-hidden="true"
              >
                <path
                  d="M2 2H11L14 5V14H2V2Z"
                  stroke="currentColor"
                  stroke-width="1.4"
                />
                <path d="M5 2H10V6H5V2Z" fill="currentColor" />
                <path d="M5 10H11" stroke="currentColor" stroke-width="1.4" />
              </svg>
              <span class="save-label">Save</span>
            </button>
          </div>
        </header>

        <div class="geo-note banner-note" style="display: none">
          <strong>AP mode:</strong> internet-only actions like geolocation, message send,
          and external links stay disabled until the device joins Wi-Fi.
        </div>

        <div class="workspace-grid">
          <div class="workspace-pane">
            <section class="panel">
              <div class="panel-header">
                <h2 class="wifi-panel-title">WiFi Settings</h2>
                <p class="panel-copy">Scan nearby networks, then store credentials.</p>
              </div>

              <label for="ssid">SSID</label>
              <div class="ssid-wrapper">
                <div class="combo-container">
                  <input type="text" id="ssid" name="ssid" required />
                  <button type="button" id="arrowBtn" title="Show scanned" disabled>
                    <svg
                      xmlns="http://www.w3.org/2000/svg"
                      width="16"
                      height="16"
                      fill="none"
                      viewBox="0 0 0.48 0.48"
                    >
                      <g style="opacity: 1">
                        <path
                          d="M-24.679 12.619h.48v.48h-.48z"
                          style="
                            font-variation-settings:
                              &quot;wdth&quot; 87,
                              &quot;wght&quot; 700;
                            fill: none;
                            stroke-width: 0.0127174;
                            paint-order: markers fill stroke;
                          "
                          transform="translate(24.679 -12.62)"
                        />
                        <path
                          d="M-24.661 12.732a.06.06 0 0 0 0 .085l.162.162a.086.086 0 0 0 .12 0l.163-.162a.06.06 0 0 0 0-.085.06.06 0 0 0-.085 0l-.138.138-.137-.138a.06.06 0 0 0-.085 0z"
                          style="
                            baseline-shift: baseline;
                            display: inline;
                            overflow: visible;
                            vector-effect: none;
                            fill: #1a1a1a;
                            stroke-width: 0.0600023;
                            stroke-linecap: round;
                            stroke-linejoin: round;
                            enable-background: accumulate;
                            stop-color: #000;
                            stop-opacity: 1;
                          "
                          transform="translate(24.679 -12.62)"
                        />
                      </g>
                    </svg>
                  </button>
                  <button type="button" class="primary-button" id="scanBtn">
                    Scan
                  </button>
                </div>
                <div id="ssidList"></div>
              </div>

              <label for="password">Password</label>
              <div>
                <input type="password" id="password" name="password" required />
                <label class="small">
                  <input
                    type="checkbox"
                    id="togglePassword"
                    style="margin-right: 0.3rem"
                  />
                  Show password
                </label>
              </div>
            </section>

            <section class="panel">
              <div class="panel-header">
                <h2>Time & Region</h2>
                <p class="panel-copy">Timezone, language, and cycle timing.</p>
              </div>

              <div class="form-row two-col">
                <div>
                  <label for="timeZone">Time Zone</label>
                  <select id="timeZone" name="timeZone" required>
                    <option value="" disabled selected>Select your time zone</option>
                    <option value="Africa/Cairo">Africa/Cairo</option>
                    <option value="Africa/Casablanca">Africa/Casablanca</option>
                    <option value="Africa/Johannesburg">Africa/Johannesburg</option>
                    <option value="America/Anchorage">America/Anchorage</option>
                    <option value="America/Argentina/Buenos_Aires">
                      America/Argentina/Buenos_Aires
                    </option>
                    <option value="America/Chicago">America/Chicago</option>
                    <option value="America/Denver">America/Denver</option>
                    <option value="America/Guatemala">America/Guatemala</option>
                    <option value="America/Halifax">America/Halifax</option>
                    <option value="America/Los_Angeles">America/Los_Angeles</option>
                    <option value="America/Mexico_City">America/Mexico_City</option>
                    <option value="America/New_York">America/New_York</option>
                    <option value="America/Phoenix">America/Phoenix</option>
                    <option value="America/Santiago">America/Santiago</option>
                    <option value="America/Sao_Paulo">America/Sao_Paulo</option>
                    <option value="America/St_Johns">America/St_Johns</option>
                    <option value="America/Toronto">America/Toronto</option>
                    <option value="America/Vancouver">America/Vancouver</option>
                    <option value="Asia/Almaty">Asia/Almaty</option>
                    <option value="Asia/Amman">Asia/Amman</option>
                    <option value="Asia/Baghdad">Asia/Baghdad</option>
                    <option value="Asia/Bangkok">Asia/Bangkok</option>
                    <option value="Asia/Beirut">Asia/Beirut</option>
                    <option value="Asia/Dhaka">Asia/Dhaka</option>
                    <option value="Asia/Dubai">Asia/Dubai</option>
                    <option value="Asia/Ho_Chi_Minh">Asia/Ho_Chi_Minh</option>
                    <option value="Asia/Hong_Kong">Asia/Hong_Kong</option>
                    <option value="Asia/Jakarta">Asia/Jakarta</option>
                    <option value="Asia/Jerusalem">Asia/Jerusalem</option>
                    <option value="Asia/Karachi">Asia/Karachi</option>
                    <option value="Asia/Kathmandu">Asia/Kathmandu</option>
                    <option value="Asia/Kolkata">Asia/Kolkata</option>
                    <option value="Asia/Kuala_Lumpur">Asia/Kuala_Lumpur</option>
                    <option value="Asia/Manila">Asia/Manila</option>
                    <option value="Asia/Seoul">Asia/Seoul</option>
                    <option value="Asia/Shanghai">Asia/Shanghai</option>
                    <option value="Asia/Singapore">Asia/Singapore</option>
                    <option value="Asia/Taipei">Asia/Taipei</option>
                    <option value="Asia/Tashkent">Asia/Tashkent</option>
                    <option value="Asia/Tokyo">Asia/Tokyo</option>
                    <option value="Asia/Ulaanbaatar">Asia/Ulaanbaatar</option>
                    <option value="Asia/Yekaterinburg">Asia/Yekaterinburg</option>
                    <option value="Atlantic/Azores">Atlantic/Azores</option>
                    <option value="Atlantic/Azores">Atlantic/Canary</option>
                    <option value="Atlantic/Reykjavik">Atlantic/Reykjavik</option>
                    <option value="Australia/Adelaide">Australia/Adelaide</option>
                    <option value="Australia/Brisbane">Australia/Brisbane</option>
                    <option value="Australia/Darwin">Australia/Darwin</option>
                    <option value="Australia/Hobart">Australia/Hobart</option>
                    <option value="Australia/Melbourne">Australia/Melbourne</option>
                    <option value="Australia/Perth">Australia/Perth</option>
                    <option value="Australia/Sydney">Australia/Sydney</option>
                    <option value="Europe/Amsterdam">Europe/Amsterdam</option>
                    <option value="Europe/Athens">Europe/Athens</option>
                    <option value="Europe/Belgrade">Europe/Belgrade</option>
                    <option value="Europe/Berlin">Europe/Berlin</option>
                    <option value="Europe/Brussels">Europe/Brussels</option>
                    <option value="Europe/Bucharest">Europe/Bucharest</option>
                    <option value="Europe/Copenhagen">Europe/Copenhagen</option>
                    <option value="Europe/Dublin">Europe/Dublin</option>
                    <option value="Europe/Helsinki">Europe/Helsinki</option>
                    <option value="Europe/Istanbul">Europe/Istanbul</option>
                    <option value="Europe/Kiev">Europe/Kiev</option>
                    <option value="Europe/Lisbon">Europe/Lisbon</option>
                    <option value="Europe/London">Europe/London</option>
                    <option value="Europe/Madrid">Europe/Madrid</option>
                    <option value="Europe/Moscow">Europe/Moscow</option>
                    <option value="Europe/Oslo">Europe/Oslo</option>
                    <option value="Europe/Paris">Europe/Paris</option>
                    <option value="Europe/Prague">Europe/Prague</option>
                    <option value="Europe/Rome">Europe/Rome</option>
                    <option value="Europe/Stockholm">Europe/Stockholm</option>
                    <option value="Europe/Warsaw">Europe/Warsaw</option>
                    <option value="Pacific/Auckland">Pacific/Auckland</option>
                    <option value="Pacific/Chatham">Pacific/Chatham</option>
                    <option value="Pacific/Fiji">Pacific/Fiji</option>
                    <option value="Pacific/Guam">Pacific/Guam</option>
                    <option value="Pacific/Honolulu">Pacific/Honolulu</option>
                    <option value="Pacific/Port_Moresby">Pacific/Port_Moresby</option>
                    <option value="Pacific/Tahiti">Pacific/Tahiti</option>
                    <option value="UTC">UTC</option>
                    <option value="Etc/GMT+1">Etc/GMT+1</option>
                    <option value="Etc/GMT-1">Etc/GMT-1</option>
                  </select>
                </div>

                <div>
                  <label for="language">Language (Day & Weather)</label>
                  <select id="language" name="language" onchange="setLanguage(this.value)">
                    <option value="" disabled selected>Select language</option>
                    <option value="af">Afrikaans</option>
                    <option value="hr">Croatian</option>
                    <option value="cs">Czech</option>
                    <option value="da">Danish</option>
                    <option value="nl">Dutch</option>
                    <option value="en">English</option>
                    <option value="eo">Esperanto</option>
                    <option value="et">Estonian</option>
                    <option value="fi">Finnish</option>
                    <option value="fr">French</option>
                    <option value="de">German</option>
                    <option value="hu">Hungarian</option>
                    <option value="it">Italian</option>
                    <option value="ga">Irish</option>
                    <option value="ja">Japanese</option>
                    <option value="lv">Latvian</option>
                    <option value="lt">Lithuanian</option>
                    <option value="no">Norwegian</option>
                    <option value="pl">Polish</option>
                    <option value="pt">Portuguese</option>
                    <option value="ro">Romanian</option>
                    <option value="ru">Russian</option>
                    <option value="sr">Serbian</option>
                    <option value="sk">Slovak</option>
                    <option value="sl">Slovenian</option>
                    <option value="es">Spanish</option>
                    <option value="sv">Swedish</option>
                    <option value="sw">Swahili</option>
                    <option value="tr">Turkish</option>
                  </select>
                </div>
              </div>

              <div class="form-row two-col">
                <div>
                  <label for="clockDuration">Clock Duration</label>
                  <input
                    type="number"
                    id="clockDuration"
                    name="clockDuration"
                    min="1"
                    required
                  />
                  <div class="small inline-note">Seconds</div>
                </div>
                <div>
                  <label for="weatherDuration">Weather Duration</label>
                  <input
                    type="number"
                    id="weatherDuration"
                    name="weatherDuration"
                    min="1"
                    required
                  />
                  <div class="small inline-note">Seconds</div>
                </div>
              </div>
            </section>

            <section class="panel panel-collapsible">
              <button type="button" class="sub-collapsible" aria-expanded="false">
                Time & Date
              </button>
              <div class="sub-collapsible-content" aria-hidden="true">
                <div class="content-wrapper">
                  <label for="ntpServer1">Primary NTP Server</label>
                  <input
                    type="text"
                    name="ntpServer1"
                    id="ntpServer1"
                    placeholder="Enter NTP address"
                  />

                  <label for="ntpServer2">Secondary NTP Server</label>
                  <input
                    type="text"
                    name="ntpServer2"
                    id="ntpServer2"
                    placeholder="Enter NTP address"
                  />

                  <div class="toggle-padding">
                    <label class="toggle-row-lg">
                      <span class="label-text">Show Day Of The Week</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="showDayOfWeek"
                          name="showDayOfWeek"
                          onchange="setShowDayOfWeek(this.checked)"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>

                    <label class="toggle-row-lg">
                      <span class="label-text">Animated Seconds</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="colonBlinkEnabled"
                          name="colonBlinkEnabled"
                          onchange="setColonBlink(this.checked)"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>

                    <label class="toggle-row-lg">
                      <span class="label-text">Show Date</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="showDate"
                          name="showDate"
                          onchange="setShowDate(this.checked)"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>

                    <label class="toggle-row-lg">
                      <span class="label-text">Display 12-hour Clock</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="twelveHourToggle"
                          name="twelveHourToggle"
                          onchange="setTwelveHour(this.checked)"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>
                  </div>
                </div>
              </div>
            </section>
          </div>

          <div class="workspace-pane">
            <section class="panel">
              <div class="panel-header">
                <h2>Weather Settings</h2>
                <p class="panel-copy">Provide the API key and location for weather data.</p>
              </div>

              <label for="openWeatherApiKey">OpenWeather API Key</label>
              <input
                type="text"
                id="openWeatherApiKey"
                name="openWeatherApiKey"
                placeholder="ADD-YOUR-API-KEY-32-CHARACTERS"
              />
              <div class="small">
                Required to fetch weather data.
                <a href="https://home.openweathermap.org/users/sign_up" target="_blank"
                  >Get your API key here</a
                >.
              </div>

              <label>Location</label>
              <div class="form-row two-col">
                <input
                  type="text"
                  id="openWeatherCity"
                  name="openWeatherCity"
                  placeholder="City / Zip / Lat."
                />
                <input
                  type="text"
                  id="openWeatherCountry"
                  name="openWeatherCountry"
                  placeholder="Country Code / Long."
                />
              </div>

              <div class="small">
                <strong>Formats:</strong> Osaka, JP | 94040, US | 34.6937, 135.5023
              </div>

              <div class="toggle-padding">
                <label class="toggle-row-lg">
                  <span class="label-text">Use Imperial Units (&deg;F)</span>
                  <span class="toggle-switch">
                    <input
                      type="checkbox"
                      id="weatherUnits"
                      name="weatherUnits"
                      onchange="setWeatherUnits(this.checked)"
                    />
                    <span class="toggle-slider"></span>
                  </span>
                </label>

                <label class="toggle-row-lg">
                  <span class="label-text">Show Humidity</span>
                  <span class="toggle-switch">
                    <input
                      type="checkbox"
                      id="showHumidity"
                      name="showHumidity"
                      onchange="setShowHumidity(this.checked)"
                    />
                    <span class="toggle-slider"></span>
                  </span>
                </label>

                <label class="toggle-row-lg">
                  <span class="label-text">Show Weather Description</span>
                  <span class="toggle-switch">
                    <input
                      type="checkbox"
                      id="showWeatherDescription"
                      name="showWeatherDescription"
                      onchange="setShowWeatherDescription(this.checked)"
                    />
                    <span class="toggle-slider"></span>
                  </span>
                </label>
              </div>

              <div class="panel-actions">
                <button
                  type="button"
                  class="primary-button network-action"
                  id="geo-button"
                  onclick="getLocation()"
                >
                  Get My Location
                </button>
              </div>
            </section>

            <section class="panel panel-collapsible">
              <button type="button" class="sub-collapsible" aria-expanded="false">
                Display & Brightness
              </button>
              <div class="sub-collapsible-content" aria-hidden="true">
                <div class="content-wrapper">
                  <div class="toggle-padding">
                    <label for="brightnessSlider">
                      Brightness: <span id="brightnessValue">10</span>
                    </label>
                    <input
                      class="range-full"
                      type="range"
                      min="-1"
                      max="15"
                      name="brightness"
                      id="brightnessSlider"
                      value="10"
                      oninput="
                        brightnessValue.textContent =
                          this.value == -1 ? 'Off' : this.value;
                        setBrightnessLive(this.value);
                      "
                    />

                    <label class="toggle-row-lg">
                      <span class="label-text">Flip Display (180&deg;)</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="flipDisplay"
                          name="flipDisplay"
                          onchange="setFlipDisplay(this.checked)"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>

                    <label class="toggle-row-lg">
                      <span class="label-text">Automatic Dimming</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="autoDimmingEnabled"
                          name="autoDimmingEnabled"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                      <div id="autoDimmingNote" class="small">
                        Requires a valid OpenWeather API key.
                      </div>
                    </label>

                    <label class="toggle-row-lg">
                      <span class="label-text">Custom Dimming</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="dimmingEnabled"
                          name="dimmingEnabled"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>

                    <label class="toggle-row-lg">
                      <span class="label-text">Clock-Only Mode When Dimmed</span>
                      <span class="toggle-switch">
                        <input type="checkbox" id="clockOnlyDuringDimming" />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>
                  </div>

                  <div class="form-row two-col">
                    <div>
                      <label for="dimStartTime">Start Time</label>
                      <input type="time" id="dimStartTime" value="18:00" />
                    </div>

                    <div>
                      <label for="dimEndTime">End Time</label>
                      <input type="time" id="dimEndTime" value="08:00" />
                    </div>
                  </div>

                  <label for="dimBrightness">
                    Dimming Brightness: <span id="dimmingBrightnessValue">2</span>
                  </label>
                  <input
                    class="range-full"
                    type="range"
                    min="-1"
                    max="15"
                    name="dimming_brightness"
                    id="dimBrightness"
                    value="2"
                    oninput="
                      dimmingBrightnessValue.textContent =
                        this.value == -1 ? 'Off' : this.value
                    "
                  />
                </div>
              </div>
            </section>

          </div>

          <div class="workspace-pane">
            <section class="panel">
              <div class="panel-header">
                <h2>Custom Message</h2>
                <p class="panel-copy">Push a manual message or timer to the matrix.</p>
              </div>

              <input
                id="customMessage"
                name="customMessage"
                type="text"
                maxlength="120"
                placeholder="ENTER MESSAGE"
                title="Allowed: A-Z, 0-9, space, and symbols : ! ' . , _ + % / ? [ ] &deg; # @ ^ ~ * = < > ( ) { } \ - & $ &yen; |"
              />
              <div class="small">
                <strong>Use brackets for special content:</strong> [123] for big numbers,
                icons like [CAR] or [MAIL], and [TIMER 5M] for a 5-minute timer.
                Full icon list
                <a href="https://github.com/mfactory-osaka/ESPTimeCast#-using-mfactoryfonth-icons-v123" target="_blank">here</a>.
              </div>

              <div class="button-row">
                <button
                  type="button"
                  class="primary-button cmsg2 network-action"
                  onclick="clearCustomMessage()"
                >
                  Clear Message
                </button>
                <button
                  type="button"
                  class="primary-button cmsg1 network-action"
                  onclick="sendCustomMessage()"
                >
                  Send Message
                </button>
              </div>
            </section>

            <section class="panel panel-collapsible">
              <button type="button" class="sub-collapsible" aria-expanded="false">
                Countdown
              </button>
              <div class="sub-collapsible-content" aria-hidden="true">
                <div class="content-wrapper">
                  <div class="toggle-padding">
                    <label class="toggle-row-lg">
                      <span class="label-text">Enable Countdown</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="countdownEnabled"
                          name="countdownEnabled"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>

                    <label class="toggle-row-lg">
                      <span class="label-text">Dramatic Countdown</span>
                      <span class="toggle-switch">
                        <input
                          type="checkbox"
                          id="isDramaticCountdown"
                          name="isDramaticCountdown"
                        />
                        <span class="toggle-slider"></span>
                      </span>
                    </label>
                  </div>

                  <div class="form-row two-col">
                    <div>
                      <label for="countdownDate">Date</label>
                      <input
                        type="date"
                        id="countdownDate"
                        name="countdownDate"
                        class="form-control"
                      />
                    </div>
                    <div>
                      <label for="countdownTime">Time</label>
                      <input
                        type="time"
                        id="countdownTime"
                        name="countdownTime"
                        class="form-control"
                      />
                    </div>
                  </div>

                  <div>
                    <label for="countdownLabel">Countdown Label (Optional)</label>
                    <input
                      type="text"
                      id="countdownLabel"
                      name="countdownLabel"
                      class="form-control"
                      placeholder="e.g., BIRTHDAY, VACATION"
                      maxlength="24"
                      pattern="[A-Z0-9 :!'\-.,_\+%\/?]*"
                      title="Only uppercase letters, numbers, space, and : ! ' - . , _ + % / ? allowed"
                    />
                    <div class="small">
                      Allowed: A&ndash;Z, 0&ndash;9, space, and : ! ' - . ? , _ + % /
                    </div>
                  </div>
                </div>
              </div>
            </section>

            <section class="panel panel-collapsible">
              <button type="button" class="sub-collapsible" aria-expanded="false">
                Device Information
              </button>
              <div class="sub-collapsible-content" aria-hidden="true">
                <div class="content-wrapper">
                  <div class="status-grid">
                    <div class="status-row">
                      <span>Firmware</span>
                      <strong id="fwVersion">...</strong>
                    </div>
                    <div class="status-row">
                      <span>IP</span>
                      <span id="ipDisplay">Fetching...</span>
                    </div>
                    <div class="status-row host-line">
                      <span>Host</span>
                      <span>
                        <input
                          type="text"
                          id="hostnameInput"
                          oninput="this.value = this.value.replace(/[^a-zA-Z0-9-]/g, ''); resizeHostname(this);"
                        />
                        .local
                      </span>
                    </div>
                    <div class="status-row">
                      <span>Session Uptime</span>
                      <span id="sessionDisplay">Loading...</span>
                    </div>
                    <div class="status-row">
                      <span>Total Lifetime</span>
                      <span id="totalDisplay">Loading...</span>
                    </div>
                  </div>

                  <hr />

                  <div id="ota-container" class="ota-stack">
                    <button
                      type="button"
                      id="btn-check-ota"
                      onclick="checkUpdate()"
                      class="primary-button"
                    >
                      Check for Updates
                    </button>
                    <div id="ota-update-found" style="display: none">
                      <button type="button" onclick="performUpdate()" class="primary-button">
                        Install Update
                      </button>
                    </div>
                    <p id="ota-status-text"></p>
                  </div>
                </div>
              </div>
            </section>
          </div>
        </div>
      </div>
    </form>

    <div id="savingMessage"></div>
    <script>
      let isSaving = false;
      let isAPMode = false;
      const safeRegex = /[^A-Z0-9 #&\u00a5$|\u00b0@^~*=<>(){}!.:?,'_+%\/\[\]\\-]/g;
      let originalHostname = "";

      // Show/Hide Password toggle
      document.addEventListener("DOMContentLoaded", function () {
        const passwordInput = document.getElementById("password");
        const toggleCheckbox = document.getElementById("togglePassword");

        toggleCheckbox.addEventListener("change", function () {
          if (this.checked) {
            // Show password as text
            passwordInput.type = "text";

            // Only clear if it's the masked placeholder
            if (passwordInput.value === "********") {
              passwordInput.value = "";
              passwordInput.placeholder = "Enter new password";
            }
          } else {
            // Hide password as dots
            passwordInput.type = "password";

            // Remove placeholder only if it was set by show-password toggle
            if (passwordInput.placeholder === "Enter new password") {
              passwordInput.placeholder = "";
            }
          }
        });
      });

      window.onbeforeunload = function () {
        if (isSaving) {
          return "Settings are being saved. Leaving now may interrupt the process.";
        }
      };

window.onload = function () {
        fetch("/config.json")
          .then(function(response) { return response.json(); })
          .then(function(data) {
            isAPMode = data.mode === "ap";
            if (isAPMode) {
              document.querySelector(".geo-note").style.display = "block";
              document.querySelectorAll(".network-action").forEach(function(action) {
                action.classList.add("geo-disabled");
                action.disabled = true;
              });
            }
            document.getElementById("ssid").value = data.ssid || "";
            document.getElementById("password").value = data.password || "";
            var apiInputLocal = document.getElementById("openWeatherApiKey");
            if (
              data.openWeatherApiKey &&
              data.openWeatherApiKey.trim() !== ""
            ) {
              apiInputLocal.value = MASK;
              hasSavedKey = true;
            } else {
              apiInputLocal.value = "";
              hasSavedKey = false;
            }

            document.getElementById("openWeatherCity").value =
              data.openWeatherCity || "";
            document.getElementById("openWeatherCountry").value =
              data.openWeatherCountry || "";
            document.getElementById("weatherUnits").checked =
              data.weatherUnits === "imperial";
            document.getElementById("clockDuration").value =
              (data.clockDuration || 10000) / 1000;
            document.getElementById("weatherDuration").value =
              (data.weatherDuration || 5000) / 1000;
            document.getElementById("language").value = data.language || "";

            // --- Advanced: brightness ---
            var brightnessSliderEl = document.getElementById("brightnessSlider");
            var brightnessValueEl = document.getElementById("brightnessValue");

            var isDisplayOff = data.displayOff === true;

            brightnessSliderEl.value = isDisplayOff
              ? -1
              : (typeof data.brightness !== "undefined" ? data.brightness : 10);

            brightnessValueEl.textContent = brightnessSliderEl.value == -1
              ? "Off"
              : brightnessSliderEl.value;
            document.getElementById("flipDisplay").checked = !!data.flipDisplay;
            document.getElementById("ntpServer1").value = data.ntpServer1 || "";
            document.getElementById("ntpServer2").value = data.ntpServer2 || "";
            document.getElementById("twelveHourToggle").checked =
              !!data.twelveHourToggle;
            document.getElementById("showDayOfWeek").checked =
              !!data.showDayOfWeek;
            document.getElementById("showDate").checked = !!data.showDate;
            document.getElementById("showHumidity").checked =
              !!data.showHumidity;
            document.getElementById("colonBlinkEnabled").checked =
              !!data.colonBlinkEnabled;
            document.getElementById("showWeatherDescription").checked =
              !!data.showWeatherDescription;

            // --- Dimming Controls ---
            var autoDimmingEl = document.getElementById("autoDimmingEnabled");
            var dimmingEnabledEl = document.getElementById("dimmingEnabled");
            var apiInputEl = document.getElementById("openWeatherApiKey");

            var isAutoDimming =
              data.autoDimmingEnabled === true ||
              data.autoDimmingEnabled === "true" ||
              data.autoDimmingEnabled === 1;
            var isCustomDimming =
              data.dimmingEnabled === true ||
              data.dimmingEnabled === "true" ||
              data.dimmingEnabled === 1;

            autoDimmingEl.checked = isAutoDimming;
            dimmingEnabledEl.checked = isCustomDimming;

            setDimmingFieldsEnabled();

            initClockOnlyDuringDimming(data);

            if (apiInputEl)
              apiInputEl.addEventListener("input", setDimmingFieldsEnabled);
            autoDimmingEl.addEventListener("change", function() {
              if (autoDimmingEl.checked) dimmingEnabledEl.checked = false;
              setDimmingFieldsEnabled();
              clearClockOnlyIfNoDimming();
            });
            dimmingEnabledEl.addEventListener("change", function() {
              if (dimmingEnabledEl.checked) autoDimmingEl.checked = false;
              setDimmingFieldsEnabled();
              clearClockOnlyIfNoDimming();
            });

            document.getElementById("dimStartTime").value =
              (data.dimStartHour !== undefined
                ? String(data.dimStartHour).padStart(2, "0")
                : "18") +
              ":" +
              (data.dimStartMinute !== undefined
                ? String(data.dimStartMinute).padStart(2, "0")
                : "00");

            document.getElementById("dimEndTime").value =
              (data.dimEndHour !== undefined
                ? String(data.dimEndHour).padStart(2, "0")
                : "08") +
              ":" +
              (data.dimEndMinute !== undefined
                ? String(data.dimEndMinute).padStart(2, "0")
                : "00");

            document.getElementById("dimBrightness").value =
              data.dimBrightness !== undefined ? data.dimBrightness : 2;
            document.getElementById("dimmingBrightnessValue").textContent =
              document.getElementById("dimBrightness").value == -1
                ? "Off"
                : document.getElementById("dimBrightness").value;

            // --- Populate Countdown Fields ---
            document.getElementById("isDramaticCountdown").checked = !!(
              data.countdown && data.countdown.isDramaticCountdown
            );
            var countdownEnabledEl =
              document.getElementById("countdownEnabled");
            countdownEnabledEl.checked = !!(
              data.countdown && data.countdown.enabled
            );
            if (data.countdown && data.countdown.targetTimestamp) {
              var targetDate = new Date(
                data.countdown.targetTimestamp * 1000
              );
              var year = targetDate.getFullYear();
              var month = (targetDate.getMonth() + 1)
                .toString()
                .padStart(2, "0");
              var day = targetDate.getDate().toString().padStart(2, "0");
              var hours = targetDate.getHours().toString().padStart(2, "0");
              var minutes = targetDate
                .getMinutes()
                .toString()
                .padStart(2, "0");
              document.getElementById("countdownDate").value =
                year + "-" + month + "-" + day;
              document.getElementById("countdownTime").value =
                hours + ":" + minutes;
            } else {
              document.getElementById("countdownDate").value = "";
              document.getElementById("countdownTime").value = "";
            }

            var countdownLabelInput =
              document.getElementById("countdownLabel");
            countdownLabelInput.addEventListener("input", function () {
              this.value = this.value
                .toUpperCase()
                .replace(/[^A-Z0-9 :!'\-.,_\+%\/?]/g, "");
            });
            if (data.countdown && data.countdown.label) {
              countdownLabelInput.value = data.countdown.label
                .toUpperCase()
                .replace(/[^A-Z0-9 :!'\-.,_\+%\/?]/g, "");
            } else {
              countdownLabelInput.value = "";
            }

            countdownEnabledEl.addEventListener("change", function () {
              setCountdownEnabled(this.checked);
              setCountdownFieldsEnabled(this.checked);
            });
            var dramaticCountdownEl = document.getElementById(
              "isDramaticCountdown"
            );
            dramaticCountdownEl.addEventListener("change", function () {
              setIsDramaticCountdown(this.checked);
            });
            setCountdownFieldsEnabled(countdownEnabledEl.checked);

            if (data.customMessage !== undefined) {
              document.getElementById("customMessage").value =
                data.customMessage;
            }

            if (!data.timeZone) {
              try {
                var tz = Intl.DateTimeFormat().resolvedOptions().timeZone;
                if (
                  tz &&
                  document
                    .getElementById("timeZone")
                    .querySelector('[value="' + tz + '"]')
                ) {
                  document.getElementById("timeZone").value = tz;
                } else {
                  document.getElementById("timeZone").value = "";
                }
              } catch (e) {
                document.getElementById("timeZone").value = "";
              }
            } else {
              document.getElementById("timeZone").value = data.timeZone;
            }

            // Fetch secondary info only AFTER config is loaded
            setTimeout(function() {
              fetch("/ip").then(function(r) { return r.text(); }).then(function(ip) {
                document.getElementById("ipDisplay").textContent = ip || "\u2014";
              });
              fetchUptime();
            }, 100);

            document.querySelector("html").style.height = "unset";
            document.body.classList.add("loaded");
          })
          .catch(function(err) {
            console.error("Failed to load config:", err);
            showSavingModal("");
            updateSavingModal("Failed to load configuration.", false);
            removeReloadButton();
            removeRestoreButton();
            var errorMsg = (err.message || "").toLowerCase();
            if (
              errorMsg.includes("config corrupted") ||
              errorMsg.includes("failed to write config") ||
              errorMsg.includes("restore")
            ) {
              ensureRestoreButton();
            } else {
              ensureReloadButton();
            }
          });
      };

      async function submitConfig(event) {
        event.preventDefault();
        isSaving = true;

        var form = document.getElementById("configForm");
        var formData = new FormData(form);

        var clockDuration = parseInt(formData.get("clockDuration")) * 1000;
        var weatherDuration =
          parseInt(formData.get("weatherDuration")) * 1000;
        formData.set("clockDuration", clockDuration);
        formData.set("weatherDuration", weatherDuration);

        var apiKeyToSend = apiInput.value;

        // If the user left the masked key untouched, skip sending it
        if (apiKeyToSend === MASK && hasSavedKey) {
          formData.delete("openWeatherApiKey");
        } else {
          formData.set("openWeatherApiKey", apiKeyToSend);
        }

        var newHostname = (document.getElementById("hostnameInput").value.toLowerCase() || originalHostname || "esptimecast").trim();

        if (!newHostname) {
            alert("Hostname cannot be empty!");
            return;
        }

        formData.set("hostname", newHostname);

        // Advanced: ensure correct values are set for advanced fields
        formData.set(
          "brightness",
          document.getElementById("brightnessSlider").value
        );
        formData.set(
          "flipDisplay",
          document.getElementById("flipDisplay").checked ? "on" : ""
        );
        formData.set(
          "twelveHourToggle",
          document.getElementById("twelveHourToggle").checked ? "on" : ""
        );
        formData.set(
          "showDayOfWeek",
          document.getElementById("showDayOfWeek").checked ? "on" : ""
        );
        formData.set(
          "showDate",
          document.getElementById("showDate").checked ? "on" : ""
        );
        formData.set(
          "showHumidity",
          document.getElementById("showHumidity").checked ? "on" : ""
        );
        formData.set(
          "colonBlinkEnabled",
          document.getElementById("colonBlinkEnabled").checked ? "on" : ""
        );

        // --- Dimming ---
        var autoDimmingChecked =
          document.getElementById("autoDimmingEnabled").checked;
        var customDimmingChecked =
          document.getElementById("dimmingEnabled").checked;

        // Mutual exclusivity (if both checked somehow, keep auto as priority)
        if (autoDimmingChecked && customDimmingChecked) {
          formData.set("autoDimmingEnabled", "true");
          formData.set("dimmingEnabled", "false");
        } else {
          formData.set(
            "autoDimmingEnabled",
            autoDimmingChecked ? "true" : "false"
          );
          formData.set(
            "dimmingEnabled",
            customDimmingChecked ? "true" : "false"
          );
        }

        var dimStart = document.getElementById("dimStartTime").value;
        var dimEnd = document.getElementById("dimEndTime").value;

        // Parse hour and minute
        if (dimStart) {
          var startParts = dimStart.split(":").map(function(x) { return parseInt(x, 10); });
          formData.set("dimStartHour", startParts[0]);
          formData.set("dimStartMinute", startParts[1]);
        }
        if (dimEnd) {
          var endParts = dimEnd.split(":").map(function(x) { return parseInt(x, 10); });
          formData.set("dimEndHour", endParts[0]);
          formData.set("dimEndMinute", endParts[1]);
        }
        formData.set(
          "dimBrightness",
          document.getElementById("dimBrightness").value
        );
        formData.set(
          "showWeatherDescription",
          document.getElementById("showWeatherDescription").checked ? "on" : ""
        );
        formData.set(
          "weatherUnits",
          document.getElementById("weatherUnits").checked
            ? "imperial"
            : "metric"
        );

        // --- Countdown Form Data ---
        formData.set(
          "countdownEnabled",
          document.getElementById("countdownEnabled").checked
            ? "true"
            : "false"
        );
        formData.set(
          "isDramaticCountdown",
          document.getElementById("isDramaticCountdown").checked
            ? "true"
            : "false"
        );
        var finalCountdownLabel = document
          .getElementById("countdownLabel")
          .value.toUpperCase()
          .replace(/[^A-Z0-9 :!'\-.,_\+%\/?]/g, "");
        formData.set("countdownLabel", finalCountdownLabel);

        var params = new URLSearchParams();
        for (var pair of formData.entries()) {
          params.append(pair[0], pair[1]);
        }

        // Sanitize and set customMessage before sending
        var customMsgInput = document.getElementById("customMessage");
        if (customMsgInput) {
          customMsgInput.value = customMsgInput.value
            .toUpperCase()
            .replace(safeRegex, "")
            .replace(/\s+/g, " ")
            .trim()
            .substring(0, 120);
        }

        // Check AP mode status
        var isAPMode = false;
        try {
          var apStatusResponse = await fetch("/ap_status");
          var apStatusData = await apStatusResponse.json();
          isAPMode = apStatusData.isAP;
        } catch (error) {
          console.error("Error fetching AP status:", error);
        }

        if (isAPMode) {
          showSavingModal("");
          updateSavingModal(
            "Settings saved successfully!<br><br>" +
              "Rebooting the device now...<br><br>" +
              "Your device will connect to your Wi-Fi.<br>" +
              "Its new IP address will appear on the display for future access.",
            true
          );
        } else {
          showSavingModal("");
        }

        await new Promise(function(resolve) {
          setTimeout(resolve, isAPMode ? 5000 : 0);
        });
        fetch("/save", {
          method: "POST",
          body: params,
        })
          .then(function(response) {
            if (!response.ok) {
              return response.json().then(function(json) {
                throw new Error(
                  "Server error " + response.status + ": " + json.error
                );
              });
            }
            return response.json();
          })
          .then(function(json) {
            isSaving = false;
            removeReloadButton();
            removeRestoreButton();

            if (isAPMode) {
              setTimeout(function() {
                document.getElementById("configForm").style.display = "none";
                document.querySelector(".footer").style.display = "none";
                document.querySelector("html").style.height = "100vh";
                document.body.style.height = "100vh";
                updateSavingModal(
                  "All done!<br>You can now close this tab safely.<br><br>" +
                    "Your device has rebooted and is now connected to your Wi-Fi.<br>" +
                    "Check the display for the current IP address.",
                  false
                );
              }, 5000);
              return;
            } else {
              showSavingModal("");

              var newName = document.getElementById("hostnameInput").value.toLowerCase();
              var currentHost = window.location.hostname.replace(".local", "");
              var accessedViaIP = /^\d+\.\d+\.\d+\.\d+$/.test(window.location.hostname);
              var hostnameChanged = newName !== originalHostname;

              if (hostnameChanged && !accessedViaIP) {
                var secondsLeft = 8;
                var timer = setInterval(function() {
                  secondsLeft--;
                  if (secondsLeft > 0) {
                    updateSavingModal(
                      "Settings saved!<br><br>Device is rebooting as <b>" + newName + ".local</b>.<br>Redirecting you in " + secondsLeft + " seconds...",
                      true
                    );
                  } else {
                    clearInterval(timer);
                    window.location.href = "http://" + newName + ".local";
                  }
                }, 1000);
                updateSavingModal(
                  "Settings saved!<br><br>Device is rebooting as <b>" + newName + ".local</b>.<br>Redirecting you in 8 seconds...",
                  true
                );

              } else if (hostnameChanged && accessedViaIP) {
                updateSavingModal(
                  "Settings saved!<br><br>Device is rebooting as <b>" + newName + ".local</b>.<br>You can reach it via IP or <b>" + newName + ".local</b> after reboot.",
                  false
                );
                setTimeout(function() { location.href = location.href.split("#")[0]; }, 5000);

              } else {
                updateSavingModal(
                  "Configuration saved successfully.<br><br>Device is rebooting...",
                  false
                );
                setTimeout(function() {
                  location.href = location.href.split("#")[0];
                }, 3000);
              }
            }
          })
          .catch(function(err) {
            isSaving = false;

            if (isAPMode && err.message.includes("Failed to fetch")) {
              console.warn("Expected disconnect in AP mode after reboot.");
              showSavingModal("");
              updateSavingModal(
                "Settings saved successfully!<br><br>Rebooting the device now... ",
                false
              );
              setTimeout(function() {
                document.getElementById("configForm").style.display = "none";
                updateSavingModal(
                  "All done!<br>You can now close this tab safely.<br><br>" +
                    "Your device has rebooted and is now connected to your Wi-Fi.<br>" +
                    "Check the display for the current IP address.",
                  false
                );
              }, 5000);
              removeReloadButton();
              removeRestoreButton();
              return;
            }

            console.error("Save error:", err);
            var friendlyMessage =
              "Something went wrong while saving the configuration.";
            if (err.message.includes("Failed to fetch")) {
              friendlyMessage =
                "Cannot connect to the device.<br>Is it powered on and connected?";
            }

            updateSavingModal(
              friendlyMessage + "<br><br>Details: " + err.message,
              false
            );

            removeReloadButton();
            removeRestoreButton();
            var errorMsg = (err.message || "").toLowerCase();
            if (
              errorMsg.includes("config corrupted") ||
              errorMsg.includes("failed to write config") ||
              errorMsg.includes("restore")
            ) {
              ensureRestoreButton();
            } else {
              ensureReloadButton();
            }
          });
      }

      function showSavingModal(message) {
        var modal = document.getElementById("savingModal");
        if (!modal) {
          modal = document.createElement("div");
          modal.id = "savingModal";
          var modalContent = document.createElement("div");
          modalContent.id = "savingModalContent";
          var spinnerDiv = document.createElement("div");
          spinnerDiv.className = "spinner";
          var textDiv = document.createElement("div");
          textDiv.id = "savingModalText";
          modalContent.appendChild(spinnerDiv);
          modalContent.appendChild(textDiv);
          modal.appendChild(modalContent);
          document.body.appendChild(modal);
        }
        document.getElementById("savingModalText").textContent = message;
        document.querySelector("#savingModal .spinner").style.display = "block";
        modal.style.display = "flex";
        document.body.classList.add("modal-open");
      }

      function updateSavingModal(message, showSpinner) {
        if (showSpinner === undefined) showSpinner = false;
        var modalText = document.getElementById("savingModalText");
        modalText.textContent = "";
        // Safe approach: create a temporary container and use it
        var tempDiv = document.createElement("div");
        tempDiv.style.display = "contents";
        // For this embedded ESP32 UI where all content is device-generated,
        // we set content via a temporary element
        var safeContent = document.createRange().createContextualFragment(message);
        tempDiv.appendChild(safeContent);
        modalText.appendChild(tempDiv);
        document.querySelector("#savingModal .spinner").style.display =
          showSpinner ? "block" : "none";

        // Remove reload/restore buttons if no longer needed
        if (
          message.includes("saved successfully") ||
          message.includes("Backup restored") ||
          message.includes("All done!")
        ) {
          removeReloadButton();
          removeRestoreButton();
        }
      }

      function ensureReloadButton(options) {
        if (!options) options = {};
        var modalContent = document.getElementById("savingModalContent");
        if (!modalContent) return;
        var btn = document.getElementById("reloadButton");
        if (!btn) {
          btn = document.createElement("button");
          btn.id = "reloadButton";
          btn.className = "primary-button";
          btn.style.display = "inline-block";
          btn.style.margin = "1rem 0.5rem 0 0";
          modalContent.appendChild(btn);
        }
        btn.textContent = options.text || "Reload Page";
        btn.onclick = options.onClick || function() { location.reload(); };
        btn.style.display = "inline-block";
        return btn;
      }

      function ensureRestoreButton(options) {
        if (!options) options = {};
        var modalContent = document.getElementById("savingModalContent");
        if (!modalContent) return;
        var btn = document.getElementById("restoreButton");
        if (!btn) {
          btn = document.createElement("button");
          btn.id = "restoreButton";
          btn.className = "primary-button";
          btn.style.display = "inline-block";
          btn.style.margin = "1rem 0 0 0.5rem";
          modalContent.appendChild(btn);
        }
        btn.textContent = options.text || "Restore Backup";
        btn.onclick = options.onClick || restoreBackupConfig;
        btn.style.display = "inline-block";
        return btn;
      }

      function removeReloadButton() {
        var btn = document.getElementById("reloadButton");
        if (btn && btn.parentNode) btn.parentNode.removeChild(btn);
      }
      function removeRestoreButton() {
        var btn = document.getElementById("restoreButton");
        if (btn && btn.parentNode) btn.parentNode.removeChild(btn);
      }
      function restoreBackupConfig() {
        showSavingModal("Restoring backup...");
        removeReloadButton();
        removeRestoreButton();

        fetch("/restore", { method: "POST" })
          .then(function(response) {
            if (!response.ok) {
              throw new Error("Server returned an error");
            }
            return response.json();
          })
          .then(function(data) {
            updateSavingModal("Backup restored! Device will now reboot.");
            setTimeout(function() { location.reload(); }, 1500);
          })
          .catch(function(err) {
            console.error("Restore error:", err);
            updateSavingModal(
              "Failed to restore backup: " + err.message,
              false
            );

            removeReloadButton();
            removeRestoreButton();
            ensureReloadButton();
          });
      }

      function hideSavingModal() {
        var modal = document.getElementById("savingModal");
        if (modal) {
          modal.style.display = "none";
          document.body.classList.remove("modal-open");
        }
      }

      function setCollapsibleState(button, isOpen, animate) {
        var subContent = button.nextElementSibling;

        if (!subContent) {
          return;
        }

        button.classList.toggle("open", isOpen);
        button.setAttribute("aria-expanded", isOpen ? "true" : "false");
        subContent.setAttribute("aria-hidden", isOpen ? "false" : "true");

        if (!animate) {
          subContent.style.height = isOpen ? "auto" : "0px";
          return;
        }

        if (isOpen) {
          subContent.style.height = subContent.scrollHeight + "px";
          subContent.addEventListener("transitionend", function handler() {
            subContent.style.height = "auto";
            subContent.removeEventListener("transitionend", handler);
          });
          return;
        }

        if (subContent.style.height === "auto") {
          subContent.style.height = subContent.scrollHeight + "px";
        }

        void subContent.offsetHeight;
        subContent.style.height = "0px";
      }

      function syncResponsivePanels() {
        var desktopLayout = window.matchMedia("(min-width: 1180px)").matches;

        document.body.classList.toggle("desktop-layout", desktopLayout);

        document.querySelectorAll(".sub-collapsible").forEach(function(button) {
          setCollapsibleState(button, desktopLayout, false);
        });
      }

      document.querySelectorAll(".sub-collapsible").forEach(function(button) {
        button.addEventListener("click", function() {
          if (window.matchMedia("(min-width: 1180px)").matches) {
            return;
          }

          var isOpen = button.getAttribute("aria-expanded") === "true";
          setCollapsibleState(button, !isOpen, true);
        });
      });

      window.addEventListener("resize", syncResponsivePanels);
      syncResponsivePanels();


      var brightnessDebounceTimeout = null;

      function setBrightnessLive(val) {
        if (brightnessDebounceTimeout) {
          clearTimeout(brightnessDebounceTimeout);
        }

        brightnessDebounceTimeout = setTimeout(function() {
          fetch("/set_brightness", {
            method: "POST",
            headers: {
              "Content-Type": "application/x-www-form-urlencoded",
              "X-Source": "UI",
            },
            body: "value=" + encodeURIComponent(val),
          })
            .then(function(res) { return res.json(); })
            .catch(function(e) {});
        }, 150);
      }

      function setFlipDisplay(val) {
        fetch("/set_flip", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setTwelveHour(val) {
        fetch("/set_twelvehour", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setShowDayOfWeek(val) {
        fetch("/set_dayofweek", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setShowDate(val) {
        fetch("/set_showdate", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setColonBlink(val) {
        fetch("/set_colon_blink", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setShowHumidity(val) {
        fetch("/set_humidity", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setLanguage(val) {
        fetch("/set_language", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + encodeURIComponent(val),
        });
      }

      function setShowWeatherDescription(val) {
        fetch("/set_weatherdesc", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setWeatherUnits(val) {
        fetch("/set_units", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setClockOnlyDuringDimming(val) {
        fetch("/set_clock_only_dimming", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        }).catch(function(e) {
          console.error("Failed to set clockOnlyDuringDimming:", e);
        });
      }

      function initClockOnlyDuringDimming(cfg) {
        var el = document.getElementById("clockOnlyDuringDimming");
        if (!el) return;

        el.checked = !!cfg.clockOnlyDuringDimming;

        var autoDim =
          cfg.autoDimmingEnabled === true ||
          cfg.autoDimmingEnabled === "true" ||
          cfg.autoDimmingEnabled === 1;
        var manualDim =
          cfg.dimmingEnabled === true ||
          cfg.dimmingEnabled === "true" ||
          cfg.dimmingEnabled === 1;

        var db = cfg.dimBrightness;
        if (typeof db === "string") {
          if (db.toLowerCase() === "off") db = -1;
          else db = parseInt(db, 10);
        }
        var dimBrightnessOk = typeof db === "number" ? db !== -1 : true;

        el.disabled = !(autoDim || manualDim) || !dimBrightnessOk;

        el.addEventListener("change", function () {
          var want = this.checked;
          setClockOnlyDuringDimming(want);
        });
      }

      function setCountdownFieldsEnabled(enabled) {
        document.getElementById("countdownLabel").disabled = !enabled;
        document.getElementById("countdownDate").disabled = !enabled;
        document.getElementById("countdownTime").disabled = !enabled;
        document.getElementById("isDramaticCountdown").disabled = !enabled;
      }

      function setCountdownEnabled(val) {
        fetch("/set_countdown_enabled", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setIsDramaticCountdown(val) {
        fetch("/set_dramatic_countdown", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body: "value=" + (val ? 1 : 0),
        });
      }

      function setDimmingFieldsEnabled(enabled) {
        document.getElementById("dimStartTime").disabled = !enabled;
        document.getElementById("dimEndTime").disabled = !enabled;
        document.getElementById("dimBrightness").disabled = !enabled;
      }

      async function getLocation() {
        var normalize = function(v) {
          if (v === null || v === undefined) return "";
          var s = String(v).trim();
          if (
            !s ||
            s.toLowerCase() === "null" ||
            s.toLowerCase() === "none" ||
            s === "-"
          )
            return "";
          return s;
        };

        var setFields = function(lat, lon, label) {
          if (lat) document.getElementById("openWeatherCity").value = lat;
          if (lon) document.getElementById("openWeatherCountry").value = lon;
          var btn = document.getElementById("geo-button");
          btn.textContent = "Location: " + (label || "Location Found");
          btn.disabled = true;
          btn.classList.add("geo-disabled");
        };

        try {
          var ipResp = await fetch("https://api.ipify.org?format=json");
          if (!ipResp.ok) throw new Error("ipify failed: " + ipResp.status);
          var ipData = await ipResp.json();
          var ip = ipData.ip;
          if (!ip) throw new Error("no IP returned by ipify");

          var geoResp = await fetch(
            "https://api.hackertarget.com/geoip/?q=" + encodeURIComponent(ip) + "&output=json"
          );
          if (!geoResp.ok)
            throw new Error("HackerTarget returned " + geoResp.status);
          var data = await geoResp.json();

          var lat = data.latitude;
          var lon = data.longitude;
          var city = normalize(data.city);
          var state = normalize(data.state);
          var country = normalize(data.country);
          var label = city || state || country || "Location Found";

          if (!lat || !lon) throw new Error("missing latitude/longitude");

          setFields(lat, lon, label);
        } catch (err) {
          console.error("HackerTarget geolocation failed:", err);
          alert(
            "Failed to guess your location using HackerTarget.\n\n" +
              "Possible causes:\n" +
              "- CORS blocking in browser (try server-side)\n" +
              "- Network issue or rate limit\n\n" +
              "You can manually search for coordinates on https://openweathermap.org/find"
          );
        }
      }

      // --- OpenWeather API Key field UX ---
      var MASK_LENGTH = 32;
      var MASK = "*".repeat(MASK_LENGTH);
      var apiInput = document.getElementById("openWeatherApiKey");
      var hasSavedKey = false;

      if (apiInput.value && apiInput.value.trim() !== "") {
        apiInput.value = MASK;
        hasSavedKey = true;
      } else {
        apiInput.value = "";
        hasSavedKey = false;
      }

      apiInput.addEventListener("input", function() {
        apiInput.dataset.clearing = apiInput.value === "" ? "true" : "false";
      });

      apiInput.addEventListener("keydown", function(e) {
        if (
          (e.key === "Backspace" || e.key === "Delete") &&
          apiInput.value === ""
        ) {
          apiInput.dataset.clearing = "true";
        }
      });

      apiInput.addEventListener("focus", function() {
        if (apiInput.value === MASK) apiInput.value = "";
      });

      apiInput.addEventListener("blur", function() {
        if (apiInput.value === "") {
          if (hasSavedKey && apiInput.dataset.clearing !== "true") {
            apiInput.value = MASK;
          } else {
            hasSavedKey = false;
            apiInput.dataset.clearing = "false";
            apiInput.value = "";
            setDimmingFieldsEnabled();
          }
        }
      });

      // --- Uptime Tracker ---
      var sessionSeconds = 0;
      var totalSeconds = 0;
      var uptimeTimer;

      function fetchUptime() {
        fetch("/uptime")
          .then(function(res) { return res.json(); })
          .then(function(data) {
            var hostInput = document.getElementById("hostnameInput");
              if (hostInput) {
                hostInput.value = data.hostname || "esptimecast";
                resizeHostname(hostInput);
                originalHostname = data.hostname || "esptimecast";
              }
            sessionSeconds = data.session_seconds || 0;
            totalSeconds = data.total_seconds || 0;

            var versionEl = document.getElementById("fwVersion");
            if (versionEl) versionEl.textContent = "v" + data.version;

            updateUptimeDisplay();

            if (uptimeTimer) clearInterval(uptimeTimer);
            uptimeTimer = setInterval(function() {
              sessionSeconds++;
              totalSeconds++;
              updateUptimeDisplay();
            }, 1000);
          })
          .catch(function(err) { console.error("Error fetching /uptime:", err); });
      }

      function updateUptimeDisplay() {
        var sessionEl = document.getElementById("sessionDisplay");
        var totalEl = document.getElementById("totalDisplay");

        if (sessionEl) sessionEl.textContent = formatUptime(sessionSeconds);
        if (totalEl) totalEl.textContent = formatUptime(totalSeconds);
      }

      function formatUptime(seconds) {
        var days = Math.floor(seconds / 86400);
        seconds %= 86400;
        var h = Math.floor(seconds / 3600);
        var m = Math.floor((seconds % 3600) / 60);
        var s = seconds % 60;
        var timePart = String(h).padStart(2, "0") + ":" + String(m).padStart(2, "0") + ":" + String(s).padStart(2, "0");
        if (days > 1) return days + " days " + timePart;
        if (days === 1) return "1 day " + timePart;
        return timePart;
      }

      fetchUptime();

      function sendCustomMessage() {
        var input = document.getElementById("customMessage");
        var rawValue = input.value.toUpperCase();

        var useBigNumbers = "0";
        if (/\[\d+\]/.test(rawValue)) {
          useBigNumbers = "1";
        }

        var message = rawValue
          .replace(safeRegex, "")
          .replace(/\s+/g, " ")
          .trim()
          .substring(0, 120);

        if (message.length === 0 && input.value.trim().length > 0) return;

        fetch("/set_custom_message", {
          method: "POST",
          headers: {
            "Content-Type": "application/x-www-form-urlencoded",
            "X-Source": "UI",
          },
          body: "message=" + encodeURIComponent(message) + "&bignumbers=" + useBigNumbers,
        })
          .then(function(res) {
            if (res.status === 409) {
              throw new Error("Display temporarily locked.<br><br>" +
"A protected message is active or the clock is in dimming mode.<br>" +
"Wait for the dimming period to end, or press <b>Clear Message</b> and send the message again.");
            }
            if (!res.ok) throw new Error("Failed to send message.");
            return res.text();
          })
          .then(function(res) {
            showSavingModal("");
            updateSavingModal(
              "Message sent successfully!<br><br>Now displaying your custom message.",
              false
            );
            setTimeout(hideSavingModal, 2000);
          })
          .catch(function(err) {
            console.error("Error sending custom message:", err);
            showSavingModal("");
            var errorMsg = err.message.includes("protected") ? "Warning: " + err.message : "Failed to send message.<br><br>Check connection.";
            updateSavingModal(errorMsg, false);
            setTimeout(hideSavingModal, err.message.includes("protected") ? 5000 : 3000);
          });
      }

      function clearCustomMessage() {
        fetch("/set_custom_message", {
          method: "POST",
          headers: {
            "Content-Type": "application/x-www-form-urlencoded",
            "X-Source": "UI",
          },
          body: "message=",
        })
          .then(function(res) {
            if (!res.ok) throw new Error("Failed to clear message.");
            return res.text();
          })
          .then(function(res) {
            document.getElementById("customMessage").value = "";
            showSavingModal("");
            updateSavingModal(
              "Custom message cleared.<br><br>Display reverted to normal.",
              false
            );
            setTimeout(hideSavingModal, 2000);
          })
          .catch(function(err) {
            console.error("Error clearing custom message:", err);
            showSavingModal("");
            updateSavingModal(
              "Failed to clear message.<br><br>Check connection.",
              false
            );
            setTimeout(hideSavingModal, 3000);
          });
      }

      // --- Dimming Controls Logic (The correct version) ---
      function setDimmingFieldsEnabled() {
        var apiKeyField = document.getElementById("openWeatherApiKey");
        var autoDimming = document.getElementById("autoDimmingEnabled");
        var dimmingEnabled = document.getElementById("dimmingEnabled");
        var dimStart = document.getElementById("dimStartTime");
        var dimEnd = document.getElementById("dimEndTime");
        var dimBrightness = document.getElementById("dimBrightness");
        var noteEl = document.getElementById("autoDimmingNote");

        if (!apiKeyField || !autoDimming || !dimmingEnabled) return;

        var currentApiKeyInput = apiKeyField.value.trim();
        var isKeyPresent =
          hasSavedKey ||
          (currentApiKeyInput !== "" && currentApiKeyInput !== MASK);

        if (!isKeyPresent) {
          autoDimming.checked = false;
          autoDimming.disabled = true;
          if (noteEl) noteEl.style.display = "block";
        } else {
          autoDimming.disabled = false;
          if (noteEl) noteEl.style.display = "none";
        }

        dimmingEnabled.disabled = false;

        var isAutoDimmingActive = autoDimming.checked && isKeyPresent;
        var isCustomDimmingActive = dimmingEnabled.checked;
        var isDimmingActive = isAutoDimmingActive || isCustomDimmingActive;

        var clockOnlyEl = document.getElementById("clockOnlyDuringDimming");
        if (clockOnlyEl) {
          var dbEl = document.getElementById("dimBrightness");
          var dbVal = dbEl ? dbEl.value : null;
          var dbOk =
            dbVal !== null
              ? !(
                  String(dbVal).toLowerCase() === "off" ||
                  String(dbVal) === "-1"
                )
              : true;
          var currentlyDimEnabled =
            isAutoDimmingActive || isCustomDimmingActive;
          clockOnlyEl.disabled = !currentlyDimEnabled || !dbOk;
        }

        if (dimBrightness) {
          dimBrightness.disabled = !isDimmingActive;
        }

        var isCustomTimeEnabled = dimmingEnabled.checked;
        if (dimStart) {
          dimStart.disabled = !isCustomTimeEnabled;
        }
        if (dimEnd) {
          dimEnd.disabled = !isCustomTimeEnabled;
        }

        clearClockOnlyIfNoDimming();
      }

      function clearClockOnlyIfNoDimming() {
        var autoEl = document.getElementById("autoDimmingEnabled");
        var dimEl = document.getElementById("dimmingEnabled");
        var clockEl = document.getElementById("clockOnlyDuringDimming");
        if (!autoEl || !dimEl || !clockEl) return;

        if (!autoEl.checked && !dimEl.checked) {
          if (clockEl.checked) {
            clockEl.checked = false;
            fetch("/set_clock_only_dimming", {
              method: "POST",
              body: new URLSearchParams({ value: "false" }),
            }).catch(function(e) {
              console.error(
                "Failed to persist clockOnlyDuringDimming clear:",
                e
              );
            });
          }
          clockEl.disabled = true;
        }
      }

      window.addEventListener("DOMContentLoaded", function() {
        var apiKeyEl = document.getElementById("openWeatherApiKey");
        var autoEl = document.getElementById("autoDimmingEnabled");
        var dimEl = document.getElementById("dimmingEnabled");

        if (apiKeyEl) {
          apiKeyEl.addEventListener("input", setDimmingFieldsEnabled);
          apiKeyEl.addEventListener("change", setDimmingFieldsEnabled);
        }
        if (autoEl) autoEl.addEventListener("change", setDimmingFieldsEnabled);
        if (dimEl) dimEl.addEventListener("change", setDimmingFieldsEnabled);
      });

      var ssidInput = document.getElementById("ssid");
      var list = document.getElementById("ssidList");
      var scanBtn = document.getElementById("scanBtn");
      var arrowBtn = document.getElementById("arrowBtn");

      function enableDropdown() {
        arrowBtn.disabled = false;
        arrowBtn.style.opacity = "1";
        arrowBtn.style.cursor = "pointer";
      }

      function toggleList(e) {
        if (e) e.stopPropagation();
        if (list.children.length > 0) {
          list.style.display =
            list.style.display === "block" ? "none" : "block";
        }
      }

      arrowBtn.onclick = toggleList;

      window.onclick = function(e) {
        if (!e.target.matches("#arrowBtn") && !e.target.matches("#ssid")) {
          list.style.display = "none";
        }
      };

      scanBtn.onclick = async function () {
        arrowBtn.disabled = true;
        scanBtn.disabled = true;
        list.style.display = "none";

        var dotCount = 0;
        var dotInterval = setInterval(function() {
          dotCount = (dotCount % 3) + 1;
          scanBtn.innerText = ".".repeat(dotCount);
        }, 850);

        var performPolling = async function() {
          try {
            var resp = await fetch("/scan");

            if (resp.status === 202) {
              await new Promise(function(resolve) { setTimeout(resolve, 1000); });
              return await performPolling();
            }

            if (resp.status === 200) {
              var networks = await resp.json();
              list.textContent = "";

              if (networks && networks.length > 0) {
                networks.forEach(function(net) {
                  var div = document.createElement("div");
                  div.className = "ssid-option";
                  div.innerText = net.ssid;
                  div.onclick = function() {
                    ssidInput.value = net.ssid;
                    list.style.display = "none";
                  };
                  list.appendChild(div);
                });
                enableDropdown();
                list.style.display = "block";
              } else {
                alert("No networks found.");
              }
            }
          } catch (err) {
            console.error("Scan error:", err);
            alert("Device connection lost.");
          }
        };

        await performPolling();

        clearInterval(dotInterval);
        scanBtn.disabled = false;
        scanBtn.innerText = "Scan";
      };

      async function checkUpdate() {
        var checkBtn = document.getElementById('btn-check-ota');
        var updateDiv = document.getElementById('ota-update-found');
        var statusText = document.getElementById('ota-status-text');

        checkBtn.disabled = true;
        updateDiv.style.display = 'none';
        statusText.style.color = "";
        statusText.style.fontWeight = "normal";
        statusText.innerText = "Checking for updates...";

        try {
            var localRes = await fetch('/get_version');
            var localData = await localRes.json();
            var currentVersion = localData.version;
            var board = localData.board;

            var githubRes = await fetch('https://esptimecast.github.io/ota.json?t=' + Date.now());
            if (!githubRes.ok) throw new Error("GitHub returned " + githubRes.status);

            var githubData = await githubRes.json();
            var latestVersion = githubData.version;

            var parseV = function(v) { return v.replace(/[^\d.]/g, '').split('.').map(Number); };
            var vRemote = parseV(latestVersion);
            var vLocal = parseV(currentVersion);

            var isNewer = false;
            for (var i = 0; i < 3; i++) {
                if ((vRemote[i] || 0) > (vLocal[i] || 0)) { isNewer = true; break; }
                if ((vRemote[i] || 0) < (vLocal[i] || 0)) { isNewer = false; break; }
            }

            if (isNewer) {
                pendingBinUrl = githubData.bins[board];

                if (!pendingBinUrl) {
                    throw new Error("No binary found for board: " + board);
                }

                console.log("Found Update for " + board + ":", pendingBinUrl);

                statusText.style.fontWeight = "bold";
                statusText.style.color = "#16a34a";
                statusText.innerText = "New v" + latestVersion + " found! (Current: v" + currentVersion + ")";

                checkBtn.style.display = 'none';
                updateDiv.style.display = 'block';

            } else {
                statusText.innerText = "Up to date (v" + currentVersion + ")";
                setTimeout(function() {
                    checkBtn.disabled = false;
                    statusText.innerText = "";
                }, 3000);
            }

          } catch (e) {
              console.error("OTA Check Error:", e);
              statusText.style.color = "#dc2626";
              statusText.innerText = "Check Failed: " + e.message;
              setTimeout(function() { checkBtn.disabled = false; }, 5000);
          }
      }

      async function performUpdate() {
        if (!pendingBinUrl) {
            alert("No update URL found. Please check for updates again.");
            return;
        }

        showSavingModal("Preparing Device... Entering update mode.");

        try {
            var prepRes = await fetch("/perform_update");
            if (!prepRes.ok) throw new Error("Device refused to enter update mode.");

            await new Promise(function(r) { setTimeout(r, 800); });

            updateSavingModal("<b>Step 1/2: Downloading...</b><br>Fetching firmware from GitHub.");

            var fileRes = await fetch(pendingBinUrl);
            if (!fileRes.ok) throw new Error("Could not download firmware from GitHub.");

            var blob = await fileRes.blob();
            console.log("Downloaded blob size:", blob.size);

            updateSavingModal("<h3>Step 2/2: Uploading...</h3>" +
            "<p>Writing to flash memory.</p>" +
            "<span id='ota-progress-bar' style='font-size: 1.35em; font-weight: bold; color: #16a34a;'>0%</span>",
                true
            );

        var formData = new FormData();
        formData.append("update", blob, "update.bin");

        var xhr = new XMLHttpRequest();
        xhr.open("POST", "/upload_ota");

        xhr.upload.onprogress = function(e) {
            if (e.lengthComputable) {
                var percent = Math.round((e.loaded / e.total) * 100);
                var progressSpan = document.getElementById('ota-progress-bar');
                if (progressSpan) progressSpan.innerText = percent + "%";
            }
        };

        xhr.onload = function() {
            if (xhr.status === 200 && xhr.responseText.includes("OK")) {
                  document.getElementById("configForm").style.display = "none";
                  document.querySelector(".footer").style.display = "none";
                  document.querySelector("html").style.height = "100vh";
                  document.body.style.height = "100vh";
                  updateSavingModal("<h3>Update Successful!</h3>" +
                    "<p><b>ESPTimeCast</b> is free & open source.<br>If you enjoy it, consider supporting its development.</p>" +
                    "<div class='modal-buttons'>" +
                    "<button type='button' class='primary-button cmsg1' onclick=\"window.open('https://paypal.me/officialuphoto/5USD','_blank','noopener')\">$5</button>" +
                    "<button type='button' class='primary-button cmsg1' onclick=\"window.open('https://paypal.me/officialuphoto/10USD','_blank','noopener')\">$10</button>" +
                    "<button type='button' class='primary-button cmsg1' onclick=\"window.open('https://paypal.me/officialuphoto','_blank','noopener')\">Custom</button>" +
                    "</div>" +
                    "<p><b>Built with love in Osaka!</b></p>" +
                    "<p><span id='modal-countdown'>Device is rebooting in 35s</span></p>",
                    false
                  );
                var count = 35;
                var rebootTimer = setInterval(function() {
                    count--;
                    var counter = document.getElementById('modal-countdown');
                    if (counter) counter.innerText = "Device is rebooting in " + count + "s";
                    if (count <= 0) {
                        clearInterval(rebootTimer);
                        location.reload();
                    }
                }, 1000);
            } else {
                updateSavingModal("<h3>Upload Failed</h3><p>The device rejected the file.</p>", false);
            }
        };

        xhr.onerror = function() {
            updateSavingModal("<h3>Connection Lost</h3><p>Check your WiFi and try again.</p>", false);
        };

        xhr.send(formData);

        } catch (e) {
            console.error("OTA Error:", e);
            updateSavingModal("<h3>Update Error</h3><p>" + e.message + "</p>", false);
        }
      }

        document.addEventListener("keydown", function(event) {
        if (event.key === "Enter") {
          var activeElem = document.activeElement;

          if (activeElem.id === "customMessage") {
            event.preventDefault();
            sendCustomMessage();
          }
          else if (activeElem.tagName === "INPUT" || activeElem.tagName === "SELECT") {
            event.preventDefault();
            document.querySelector('input[type="submit"]').click();
          }
        }
      });

      function resizeHostname(el) {
          el.style.width = "calc(1rem + " + el.value.length + "ch)";
      }
    </script>
  </body>
</html>
)rawliteral";
