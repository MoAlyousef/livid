/*
MIT License

Copyright (c) 2021 Mohammed Alyousef

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <cstdio>
#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace livid {

using Event = emscripten::val;

/// List of all available Html elements
enum class HTMLElementType {
    Address,
    Article,
    Aside,
    Footer,
    Header,
    H1,
    H2,
    H3,
    H4,
    H5,
    H6,
    Main,
    Nav,
    Section,
    Blockquote,
    Dd,
    Div,
    Dl,
    Dt,
    Figcaption,
    Figure,
    Hr,
    Li,
    Ol,
    P,
    Pre,
    Ul,
    A,
    Abbr,
    B,
    Bdi,
    Bdo,
    Br,
    Cite,
    Code,
    Data,
    Dfn,
    Em,
    I,
    Kbd,
    Mark,
    Q,
    Rp,
    Rt,
    Ruby,
    S,
    Samp,
    Small,
    Span,
    Strong,
    Sub,
    Sup,
    Time,
    U,
    Var,
    Wbr,
    Area,
    Audio,
    Img,
    Map,
    Track,
    Video,
    Embed,
    Iframe,
    Object,
    Param,
    Picture,
    Portal,
    Source,
    Svg,
    Math,
    Canvas,
    Noscript,
    Script,
    Del,
    Ins,
    Caption,
    Col,
    Colgroup,
    Table,
    Tbody,
    Td,
    Tfoot,
    Th,
    Thead,
    Tr,
    Button,
    Datalist,
    Fieldset,
    Form,
    Input,
    Label,
    Legend,
    Meter,
    Optgroup,
    Option,
    Output,
    Progress,
    Select,
    Textarea,
    Details,
    Dialog,
    Menu,
    Summary,
    Slot,
    Template,
};

/// List of all available events
enum class EventType {
    Abort,
    Afterprint,
    Animationend,
    Animationiteration,
    Animationstart,
    Beforeprint,
    Beforeunload,
    Blur,
    Canplay,
    Canplaythrough,
    Change,
    Click,
    Contextmenu,
    Copy,
    Cut,
    Dblclick,
    Drag,
    Dragend,
    Dragenter,
    Dragleave,
    Dragover,
    Dragstart,
    Drop,
    Durationchange,
    Ended,
    Error,
    Focus,
    Focusin,
    Focusout,
    Fullscreenchange,
    Fullscreenerror,
    Hashchange,
    Input,
    Invalid,
    Keydown,
    Keypress,
    Keyup,
    Load,
    Loadeddata,
    Loadedmetadata,
    Loadstart,
    Message,
    Mousedown,
    Mouseenter,
    Mouseleave,
    Mousemove,
    Mouseover,
    Mouseout,
    Mouseup,
    Mousewheel,
    Offline,
    Online,
    Open,
    Pagehide,
    Pageshow,
    Paste,
    Pause,
    Play,
    Playing,
    Popstate,
    Progress,
    Ratechange,
    Resize,
    Reset,
    Scroll,
    Search,
    Seeked,
    Seeking,
    Select,
    Show,
    Stalled,
    Storage,
    Submit,
    Suspend,
    Timeupdate,
    Toggle,
    Touchcancel,
    Touchend,
    Touchmove,
    Touchstart,
    Transitionend,
    Unload,
    Volumechange,
    Waiting,
    Wheel,
};

enum class Style {
    AlignContent,
    AlignItems,
    AlignSelf,
    Animation,
    AnimationDelay,
    AnimationDirection,
    AnimationDuration,
    AnimationFillMode,
    AnimationIterationCount,
    AnimationName,
    AnimationTimingFunction,
    AnimationPlayState,
    Background,
    BackgroundAttachment,
    BackgroundColor,
    BackgroundImage,
    BackgroundPosition,
    BackgroundRepeat,
    BackgroundClip,
    BackgroundOrigin,
    BackgroundSize,
    BackfaceVisibility,
    Border,
    BorderBottom,
    BorderBottomColor,
    BorderBottomLeftRadius,
    BorderBottomRightRadius,
    BorderBottomStyle,
    BorderBottomWidth,
    BorderCollapse,
    BorderColor,
    BorderImage,
    BorderImageOutset,
    BorderImageRepeat,
    BorderImageSlice,
    BorderImageSource,
    BorderImageWidth,
    BorderLeft,
    BorderLeftColor,
    BorderLeftStyle,
    BorderLeftWidth,
    BorderRadius,
    BorderRight,
    BorderRightColor,
    BorderRightStyle,
    BorderRightWidth,
    BorderSpacing,
    BorderStyle,
    BorderTop,
    BorderTopColor,
    BorderTopLeftRadius,
    BorderTopRightRadius,
    BorderTopStyle,
    BorderTopWidth,
    BorderWidth,
    Bottom,
    BoxDecorationBreak,
    BoxShadow,
    BoxSizing,
    CaptionSide,
    CaretColor,
    Clear,
    Clip,
    Color,
    ColumnCount,
    ColumnFill,
    ColumnGap,
    ColumnRule,
    ColumnRuleColor,
    ColumnRuleStyle,
    ColumnRuleWidth,
    Columns,
    ColumnSpan,
    ColumnWidth,
    Content,
    CounterIncrement,
    CounterReset,
    Cursor,
    Direction,
    Display,
    EmptyCells,
    Filter,
    Flex,
    FlexBasis,
    FlexDirection,
    FlexFlow,
    FlexGrow,
    FlexShrink,
    FlexWrap,
    CssFloat,
    Font,
    FontFamily,
    FontSize,
    FontStyle,
    FontVariant,
    FontWeight,
    FontSizeAdjust,
    FontStretch,
    HangingPunctuation,
    Height,
    Hyphens,
    Icon,
    ImageOrientation,
    Isolation,
    JustifyContent,
    Left,
    LetterSpacing,
    LineHeight,
    ListStyle,
    ListStyleImage,
    ListStylePosition,
    ListStyleType,
    Margin,
    MarginBottom,
    MarginLeft,
    MarginRight,
    MarginTop,
    MaxHeight,
    MaxWidth,
    MinHeight,
    MinWidth,
    NavDown,
    NavIndex,
    NavLeft,
    NavRight,
    NavUp,
    ObjectFit,
    ObjectPosition,
    Opacity,
    Order,
    Orphans,
    Outline,
    OutlineColor,
    OutlineOffset,
    OutlineStyle,
    OutlineWidth,
    Overflow,
    OverflowX,
    OverflowY,
    Padding,
    PaddingBottom,
    PaddingLeft,
    PaddingRight,
    PaddingTop,
    PageBreakAfter,
    PageBreakBefore,
    PageBreakInside,
    Perspective,
    PerspectiveOrigin,
    Position,
    Quotes,
    Resize,
    Right,
    ScrollBehavior,
    TableLayout,
    TabSize,
    TextAlign,
    TextAlignLast,
    TextDecoration,
    TextDecorationColor,
    TextDecorationLine,
    TextDecorationStyle,
    TextIndent,
    TextJustify,
    TextOverflow,
    TextShadow,
    TextTransform,
    Top,
    Transform,
    TransformOrigin,
    TransformStyle,
    Transition,
    TransitionProperty,
    TransitionDuration,
    TransitionTimingFunction,
    TransitionDelay,
    UnicodeBidi,
    UserSelect,
    VerticalAlign,
    Visibility,
    WhiteSpace,
    Width,
    WordBreak,
    WordSpacing,
    WordWrap,
    Widows,
    ZIndex,
};

namespace detail {

template <typename... Ts>
std::string format_buf(const char *fmt, Ts... ts) {
    auto sz  = snprintf(nullptr, 0, fmt, ts...);
    auto buf = std::make_unique<char[]>(sz + 1); // NOLINT
    (void)snprintf(buf.get(), sz + 1, fmt, ts...);
    std::string str(buf.get());
    return str;
}

/// [INTERNAL]
EMSCRIPTEN_BINDINGS(MyBindings) {
    emscripten::class_<std::function<void(Event)>>("ListenerCallback")
        .constructor<>()
        .function("_internal_func_", &std::function<void(Event)>::operator());
};

static emscripten::val func_to_val(std::function<void(Event)> &&func) {
    return emscripten::val(func)["_internal_func_"].call<emscripten::val>(
        "bind", emscripten::val(func)
    );
}

// clang-format off
/// [INTERNAL]
constexpr const char *get_element_str(HTMLElementType typ) {
    switch (typ) {
        case HTMLElementType::Address: return "address";
        case HTMLElementType::Article: return "article";
        case HTMLElementType::Aside: return "aside";
        case HTMLElementType::Footer: return "footer";
        case HTMLElementType::Header: return "header";
        case HTMLElementType::H1: return "h1";
        case HTMLElementType::H2: return "h2";
        case HTMLElementType::H3: return "h3";
        case HTMLElementType::H4: return "h4";
        case HTMLElementType::H5: return "h5";
        case HTMLElementType::H6: return "h6";
        case HTMLElementType::Main: return "main";
        case HTMLElementType::Nav: return "nav";
        case HTMLElementType::Section: return "section";
        case HTMLElementType::Blockquote: return "blockquote";
        case HTMLElementType::Dd: return "dd";
        case HTMLElementType::Div: return "div";
        case HTMLElementType::Dl: return "dl";
        case HTMLElementType::Dt: return "dt";
        case HTMLElementType::Figcaption: return "figcaption";
        case HTMLElementType::Figure: return "figure";
        case HTMLElementType::Hr: return "hr";
        case HTMLElementType::Li: return "li";
        case HTMLElementType::Ol: return "ol";
        case HTMLElementType::P: return "p";
        case HTMLElementType::Pre: return "pre";
        case HTMLElementType::Ul: return "ul";
        case HTMLElementType::A: return "a";
        case HTMLElementType::Abbr: return "abbr";
        case HTMLElementType::B: return "b";
        case HTMLElementType::Bdi: return "bdi";
        case HTMLElementType::Bdo: return "bdo";
        case HTMLElementType::Br: return "br";
        case HTMLElementType::Cite: return "cite";
        case HTMLElementType::Code: return "code";
        case HTMLElementType::Data: return "data";
        case HTMLElementType::Dfn: return "dfn";
        case HTMLElementType::Em: return "em";
        case HTMLElementType::I: return "i";
        case HTMLElementType::Kbd: return "kbd";
        case HTMLElementType::Mark: return "mark";
        case HTMLElementType::Q: return "q";
        case HTMLElementType::Rp: return "rp";
        case HTMLElementType::Rt: return "rt";
        case HTMLElementType::Ruby: return "ruby";
        case HTMLElementType::S: return "s";
        case HTMLElementType::Samp: return "samp";
        case HTMLElementType::Small: return "small";
        case HTMLElementType::Span: return "span";
        case HTMLElementType::Strong: return "strong";
        case HTMLElementType::Sub: return "sub";
        case HTMLElementType::Sup: return "sup";
        case HTMLElementType::Time: return "time";
        case HTMLElementType::U: return "u";
        case HTMLElementType::Var: return "var";
        case HTMLElementType::Wbr: return "wbr";
        case HTMLElementType::Area: return "area";
        case HTMLElementType::Audio: return "audio";
        case HTMLElementType::Img: return "img";
        case HTMLElementType::Map: return "map";
        case HTMLElementType::Track: return "track";
        case HTMLElementType::Video: return "video";
        case HTMLElementType::Embed: return "embed";
        case HTMLElementType::Iframe: return "iframe";
        case HTMLElementType::Object: return "object";
        case HTMLElementType::Param: return "param";
        case HTMLElementType::Picture: return "picture";
        case HTMLElementType::Portal: return "portal";
        case HTMLElementType::Source: return "source";
        case HTMLElementType::Svg: return "svg";
        case HTMLElementType::Math: return "math";
        case HTMLElementType::Canvas: return "canvas";
        case HTMLElementType::Noscript: return "noscript";
        case HTMLElementType::Script: return "script";
        case HTMLElementType::Del: return "del";
        case HTMLElementType::Ins: return "ins";
        case HTMLElementType::Caption: return "caption";
        case HTMLElementType::Col: return "col";
        case HTMLElementType::Colgroup: return "colgroup";
        case HTMLElementType::Table: return "table";
        case HTMLElementType::Tbody: return "tbody";
        case HTMLElementType::Td: return "td";
        case HTMLElementType::Tfoot: return "tfoot";
        case HTMLElementType::Th: return "th";
        case HTMLElementType::Thead: return "thead";
        case HTMLElementType::Tr: return "tr";
        case HTMLElementType::Button: return "button";
        case HTMLElementType::Datalist: return "datalist";
        case HTMLElementType::Fieldset: return "fieldset";
        case HTMLElementType::Form: return "form";
        case HTMLElementType::Input: return "input";
        case HTMLElementType::Label: return "label";
        case HTMLElementType::Legend: return "legend";
        case HTMLElementType::Meter: return "meter";
        case HTMLElementType::Optgroup: return "optgroup";
        case HTMLElementType::Option: return "option";
        case HTMLElementType::Output: return "output";
        case HTMLElementType::Progress: return "progress";
        case HTMLElementType::Select: return "select";
        case HTMLElementType::Textarea: return "textarea";
        case HTMLElementType::Details: return "details";
        case HTMLElementType::Dialog: return "dialog";
        case HTMLElementType::Menu: return "menu";
        case HTMLElementType::Summary: return "summary";
        case HTMLElementType::Slot: return "slot";
        case HTMLElementType::Template: return "template";
        default: return "div";
    }
}

constexpr const char *get_event_str(EventType ev) {
    switch (ev) {
        case EventType::Abort: return "abort";
        case EventType::Afterprint: return "afterprint";
        case EventType::Animationend: return "animationend";
        case EventType::Animationiteration: return "animationiteration";
        case EventType::Animationstart: return "animationstart";
        case EventType::Beforeprint: return "beforeprint";
        case EventType::Beforeunload: return "beforeunload";
        case EventType::Blur: return "blur";
        case EventType::Canplay: return "canplay";
        case EventType::Canplaythrough: return "canplaythrough";
        case EventType::Change: return "change";
        case EventType::Click: return "click";
        case EventType::Contextmenu: return "contextmenu";
        case EventType::Copy: return "copy";
        case EventType::Cut: return "cut";
        case EventType::Dblclick: return "dblclick";
        case EventType::Drag: return "drag";
        case EventType::Dragend: return "dragend";
        case EventType::Dragenter: return "dragenter";
        case EventType::Dragleave: return "dragleave";
        case EventType::Dragover: return "dragover";
        case EventType::Dragstart: return "dragstart";
        case EventType::Drop: return "drop";
        case EventType::Durationchange: return "durationchange";
        case EventType::Ended: return "ended";
        case EventType::Error: return "error";
        case EventType::Focus: return "focus";
        case EventType::Focusin: return "focusin";
        case EventType::Focusout: return "focusout";
        case EventType::Fullscreenchange: return "fullscreenchange";
        case EventType::Fullscreenerror: return "fullscreenerror";
        case EventType::Hashchange: return "hashchange";
        case EventType::Input: return "input";
        case EventType::Invalid: return "invalid";
        case EventType::Keydown: return "keydown";
        case EventType::Keypress: return "keypress";
        case EventType::Keyup: return "keyup";
        case EventType::Load: return "load";
        case EventType::Loadeddata: return "loadeddata";
        case EventType::Loadedmetadata: return "loadedmetadata";
        case EventType::Loadstart: return "loadstart";
        case EventType::Message: return "message";
        case EventType::Mousedown: return "mousedown";
        case EventType::Mouseenter: return "mouseenter";
        case EventType::Mouseleave: return "mouseleave";
        case EventType::Mousemove: return "mousemove";
        case EventType::Mouseover: return "mouseover";
        case EventType::Mouseout: return "mouseout";
        case EventType::Mouseup: return "mouseup";
        case EventType::Mousewheel: return "mousewheel";
        case EventType::Offline: return "offline";
        case EventType::Online: return "online";
        case EventType::Open: return "open";
        case EventType::Pagehide: return "pagehide";
        case EventType::Pageshow: return "pageshow";
        case EventType::Paste: return "paste";
        case EventType::Pause: return "pause";
        case EventType::Play: return "play";
        case EventType::Playing: return "playing";
        case EventType::Popstate: return "popstate";
        case EventType::Progress: return "progress";
        case EventType::Ratechange: return "ratechange";
        case EventType::Resize: return "resize";
        case EventType::Reset: return "reset";
        case EventType::Scroll: return "scroll";
        case EventType::Search: return "search";
        case EventType::Seeked: return "seeked";
        case EventType::Seeking: return "seeking";
        case EventType::Select: return "select";
        case EventType::Show: return "show";
        case EventType::Stalled: return "stalled";
        case EventType::Storage: return "storage";
        case EventType::Submit: return "submit";
        case EventType::Suspend: return "suspend";
        case EventType::Timeupdate: return "timeupdate";
        case EventType::Toggle: return "toggle";
        case EventType::Touchcancel: return "touchcancel";
        case EventType::Touchend: return "touchend";
        case EventType::Touchmove: return "touchmove";
        case EventType::Touchstart: return "touchstart";
        case EventType::Transitionend: return "transitionend";
        case EventType::Unload: return "unload";
        case EventType::Volumechange: return "volumechange";
        case EventType::Waiting: return "waiting";
        case EventType::Wheel: return "wheel";
    }
}

constexpr const char *get_style_str(Style s) {
    switch (s) {
        case Style::AlignContent: return "alignContent";
        case Style::AlignItems: return "alignItems";
        case Style::AlignSelf: return "alignSelf";
        case Style::Animation: return "animation";
        case Style::AnimationDelay: return "animationDelay";
        case Style::AnimationDirection: return "animationDirection";
        case Style::AnimationDuration: return "animationDuration";
        case Style::AnimationFillMode: return "animationFillMode";
        case Style::AnimationIterationCount: return "animationIterationCount";
        case Style::AnimationName: return "animationName";
        case Style::AnimationTimingFunction: return "animationTimingFunction";
        case Style::AnimationPlayState: return "animationPlayState";
        case Style::Background: return "background";
        case Style::BackgroundAttachment: return "backgroundAttachment";
        case Style::BackgroundColor: return "backgroundColor";
        case Style::BackgroundImage: return "backgroundImage";
        case Style::BackgroundPosition: return "backgroundPosition";
        case Style::BackgroundRepeat: return "backgroundRepeat";
        case Style::BackgroundClip: return "backgroundClip";
        case Style::BackgroundOrigin: return "backgroundOrigin";
        case Style::BackgroundSize: return "backgroundSize";
        case Style::BackfaceVisibility: return "backfaceVisibility";
        case Style::Border: return "border";
        case Style::BorderBottom: return "borderBottom";
        case Style::BorderBottomColor: return "borderBottomColor";
        case Style::BorderBottomLeftRadius: return "borderBottomLeftRadius";
        case Style::BorderBottomRightRadius: return "borderBottomRightRadius";
        case Style::BorderBottomStyle: return "borderBottomStyle";
        case Style::BorderBottomWidth: return "borderBottomWidth";
        case Style::BorderCollapse: return "borderCollapse";
        case Style::BorderColor: return "borderColor";
        case Style::BorderImage: return "borderImage";
        case Style::BorderImageOutset: return "borderImageOutset";
        case Style::BorderImageRepeat: return "borderImageRepeat";
        case Style::BorderImageSlice: return "borderImageSlice";
        case Style::BorderImageSource: return "borderImageSource";
        case Style::BorderImageWidth: return "borderImageWidth";
        case Style::BorderLeft: return "borderLeft";
        case Style::BorderLeftColor: return "borderLeftColor";
        case Style::BorderLeftStyle: return "borderLeftStyle";
        case Style::BorderLeftWidth: return "borderLeftWidth";
        case Style::BorderRadius: return "borderRadius";
        case Style::BorderRight: return "borderRight";
        case Style::BorderRightColor: return "borderRightColor";
        case Style::BorderRightStyle: return "borderRightStyle";
        case Style::BorderRightWidth: return "borderRightWidth";
        case Style::BorderSpacing: return "borderSpacing";
        case Style::BorderStyle: return "borderStyle";
        case Style::BorderTop: return "borderTop";
        case Style::BorderTopColor: return "borderTopColor";
        case Style::BorderTopLeftRadius: return "borderTopLeftRadius";
        case Style::BorderTopRightRadius: return "borderTopRightRadius";
        case Style::BorderTopStyle: return "borderTopStyle";
        case Style::BorderTopWidth: return "borderTopWidth";
        case Style::BorderWidth: return "borderWidth";
        case Style::Bottom: return "bottom";
        case Style::BoxDecorationBreak: return "boxDecorationBreak";
        case Style::BoxShadow: return "boxShadow";
        case Style::BoxSizing: return "boxSizing";
        case Style::CaptionSide: return "captionSide";
        case Style::CaretColor: return "caretColor";
        case Style::Clear: return "clear";
        case Style::Clip: return "clip";
        case Style::Color: return "color";
        case Style::ColumnCount: return "columnCount";
        case Style::ColumnFill: return "columnFill";
        case Style::ColumnGap: return "columnGap";
        case Style::ColumnRule: return "columnRule";
        case Style::ColumnRuleColor: return "columnRuleColor";
        case Style::ColumnRuleStyle: return "columnRuleStyle";
        case Style::ColumnRuleWidth: return "columnRuleWidth";
        case Style::Columns: return "columns";
        case Style::ColumnSpan: return "columnSpan";
        case Style::ColumnWidth: return "columnWidth";
        case Style::Content: return "content";
        case Style::CounterIncrement: return "counterIncrement";
        case Style::CounterReset: return "counterReset";
        case Style::Cursor: return "cursor";
        case Style::Direction: return "direction";
        case Style::Display: return "display";
        case Style::EmptyCells: return "emptyCells";
        case Style::Filter: return "filter";
        case Style::Flex: return "flex";
        case Style::FlexBasis: return "flexBasis";
        case Style::FlexDirection: return "flexDirection";
        case Style::FlexFlow: return "flexFlow";
        case Style::FlexGrow: return "flexGrow";
        case Style::FlexShrink: return "flexShrink";
        case Style::FlexWrap: return "flexWrap";
        case Style::CssFloat: return "cssFloat";
        case Style::Font: return "font";
        case Style::FontFamily: return "fontFamily";
        case Style::FontSize: return "fontSize";
        case Style::FontStyle: return "fontStyle";
        case Style::FontVariant: return "fontVariant";
        case Style::FontWeight: return "fontWeight";
        case Style::FontSizeAdjust: return "fontSizeAdjust";
        case Style::FontStretch: return "fontStretch";
        case Style::HangingPunctuation: return "hangingPunctuation";
        case Style::Height: return "height";
        case Style::Hyphens: return "hyphens";
        case Style::Icon: return "icon";
        case Style::ImageOrientation: return "imageOrientation";
        case Style::Isolation: return "isolation";
        case Style::JustifyContent: return "justifyContent";
        case Style::Left: return "left";
        case Style::LetterSpacing: return "letterSpacing";
        case Style::LineHeight: return "lineHeight";
        case Style::ListStyle: return "listStyle";
        case Style::ListStyleImage: return "listStyleImage";
        case Style::ListStylePosition: return "listStylePosition";
        case Style::ListStyleType: return "listStyleType";
        case Style::Margin: return "margin";
        case Style::MarginBottom: return "marginBottom";
        case Style::MarginLeft: return "marginLeft";
        case Style::MarginRight: return "marginRight";
        case Style::MarginTop: return "marginTop";
        case Style::MaxHeight: return "maxHeight";
        case Style::MaxWidth: return "maxWidth";
        case Style::MinHeight: return "minHeight";
        case Style::MinWidth: return "minWidth";
        case Style::NavDown: return "navDown";
        case Style::NavIndex: return "navIndex";
        case Style::NavLeft: return "navLeft";
        case Style::NavRight: return "navRight";
        case Style::NavUp: return "navUp";
        case Style::ObjectFit: return "objectFit";
        case Style::ObjectPosition: return "objectPosition";
        case Style::Opacity: return "opacity";
        case Style::Order: return "order";
        case Style::Orphans: return "orphans";
        case Style::Outline: return "outline";
        case Style::OutlineColor: return "outlineColor";
        case Style::OutlineOffset: return "outlineOffset";
        case Style::OutlineStyle: return "outlineStyle";
        case Style::OutlineWidth: return "outlineWidth";
        case Style::Overflow: return "overflow";
        case Style::OverflowX: return "overflowX";
        case Style::OverflowY: return "overflowY";
        case Style::Padding: return "padding";
        case Style::PaddingBottom: return "paddingBottom";
        case Style::PaddingLeft: return "paddingLeft";
        case Style::PaddingRight: return "paddingRight";
        case Style::PaddingTop: return "paddingTop";
        case Style::PageBreakAfter: return "pageBreakAfter";
        case Style::PageBreakBefore: return "pageBreakBefore";
        case Style::PageBreakInside: return "pageBreakInside";
        case Style::Perspective: return "perspective";
        case Style::PerspectiveOrigin: return "perspectiveOrigin";
        case Style::Position: return "position";
        case Style::Quotes: return "quotes";
        case Style::Resize: return "resize";
        case Style::Right: return "right";
        case Style::ScrollBehavior: return "scrollBehavior";
        case Style::TableLayout: return "tableLayout";
        case Style::TabSize: return "tabSize";
        case Style::TextAlign: return "textAlign";
        case Style::TextAlignLast: return "textAlignLast";
        case Style::TextDecoration: return "textDecoration";
        case Style::TextDecorationColor: return "textDecorationColor";
        case Style::TextDecorationLine: return "textDecorationLine";
        case Style::TextDecorationStyle: return "textDecorationStyle";
        case Style::TextIndent: return "textIndent";
        case Style::TextJustify: return "textJustify";
        case Style::TextOverflow: return "textOverflow";
        case Style::TextShadow: return "textShadow";
        case Style::TextTransform: return "textTransform";
        case Style::Top: return "top";
        case Style::Transform: return "transform";
        case Style::TransformOrigin: return "transformOrigin";
        case Style::TransformStyle: return "transformStyle";
        case Style::Transition: return "transition";
        case Style::TransitionProperty: return "transitionProperty";
        case Style::TransitionDuration: return "transitionDuration";
        case Style::TransitionTimingFunction: return "transitionTimingFunction";
        case Style::TransitionDelay: return "transitionDelay";
        case Style::UnicodeBidi: return "unicodeBidi";
        case Style::UserSelect: return "userSelect";
        case Style::VerticalAlign: return "verticalAlign";
        case Style::Visibility: return "visibility";
        case Style::WhiteSpace: return "whiteSpace";
        case Style::Width: return "width";
        case Style::WordBreak: return "wordBreak";
        case Style::WordSpacing: return "wordSpacing";
        case Style::WordWrap: return "wordWrap";
        case Style::Widows: return "widows";
        case Style::ZIndex: return "zIndex";
    }
}
// clang-format on
} // namespace detail

/// Holds the implementation of all elements, not specific to HTMLElementType
class HTMLElement {
  protected:
    emscripten::val v = emscripten::val::null(); // NOLINT

    HTMLElement() = default;

  public:
    operator emscripten::val() const { return v; }
    HTMLElement(emscripten::val val) : v(val) {
        if (!val.instanceof (emscripten::val::global("HTMLElement")))
            throw std::runtime_error("Element is not an HTML Element");
    }

    /// Creates a HTMLElement from a HTMLElementType
    HTMLElement(const HTMLElementType typ) {
        if (typ == HTMLElementType::Svg) {
            auto doc = emscripten::val::global("document");
            v        = doc.call<emscripten::val>(
                "createElementNS",
                emscripten::val("http://www.w3.org/2000/svg"),
                emscripten::val("svg")
            );
            doc.call<emscripten::val>(
                   "getElementsByTagName", emscripten::val("body")
            )[0]
                .call<void>("appendChild", v);
        } else {
            const char *element = detail::get_element_str(typ);
            auto doc            = emscripten::val::global("document");
            v                   = doc.call<emscripten::val>(
                "createElement", emscripten::val(element)
            );
            doc.call<emscripten::val>(
                   "getElementsByTagName", emscripten::val("body")
            )[0]
                .call<void>("appendChild", v);
        }
    }

    /// Creates a namespaced element, calls `createElementNS`
    HTMLElement(const std::string &name_space, const std::string &tag)
        : HTMLElement() {
        auto doc = emscripten::val::global("document");
        v = doc.call<emscripten::val>("createElementNS", name_space, tag);
        doc.call<emscripten::val>(
               "getElementsByTagName", emscripten::val("body")
        )[0]
            .call<void>("appendChild", v);
    }

    /// Construct a HTMLElement from an html id
    static HTMLElement from_id(const std::string &id) {
        auto doc  = emscripten::val::global("document");
        auto elem = doc.call<emscripten::val>(
            "getElementById", emscripten::val(id.c_str())
        );
        if (!elem.instanceof (emscripten::val::global("HTMLElement")))
            throw std::runtime_error("Element is not an HTML Element");
        return {elem};
    }

    /// Delete a HTMLElement
    static void delete_element(HTMLElement &&elem) { elem.outer_html(""); }

    /// Get the Html id
    [[nodiscard]] std::string id() const { return v["id"].as<std::string>(); }

    /// Set the Html id
    HTMLElement &id(const std::string &val) {
        v.set("id", val);
        return *this;
    }

    /// Set the Html attribute
    HTMLElement &attr(const std::string &attr, const std::string &val) {
        v.call<void>("setAttribute", attr, val);
        return *this;
    }

    /// Get the Html attribute
    std::string attr(const std::string &attr) {
        return v.call<emscripten::val>("getAttribute", attr).as<std::string>();
    }

    /// Set the Html class
    HTMLElement &klass(const char *val) {
        v.set("className", val);
        return *this;
    }

    /// Get the Html class
    std::string klass() { return v["className"].as<std::string>(); }

    /// Append a child
    HTMLElement &append(const HTMLElement &w) {
        v.call<void>("appendChild", w.v);
        return *this;
    }

    /// Remove a child
    HTMLElement &remove(const HTMLElement &w) {
        v.call<void>("removeChild", w.v);
        return *this;
    }

    /// Add an event listener
    HTMLElement &handle(EventType event, std::function<void(Event)> &&func) {
        v.call<void>(
            "addEventListener",
            std::string(detail::get_event_str(event)),
            detail::func_to_val(std::move(func))
        );
        return *this;
    }

    /// Set the text content
    HTMLElement &text(const std::string &html) {
        v.set("textContent", html);
        return *this;
    }

    /// Get the text content
    std::string text() { return v["textContent"].as<std::string>(); }

    /// Set the outer html
    HTMLElement &outer_html(const std::string &html) {
        v.set("outerHTML", html);
        return *this;
    }

    /// Get the outer html
    std::string outer_html() { return v["outerHTML"].as<std::string>(); }

    /// Set the inner html
    HTMLElement &inner_html(const std::string &html) {
        v.set("innerHTML", html);
        return *this;
    }

    /// Get the inner html
    std::string inner_html() { return v["innerHTML"].as<std::string>(); }

    /// Set the href value
    HTMLElement &href(const std::string &html) {
        v.set("href", html);
        return *this;
    }

    /// Get the href value
    std::string href() { return v["href"].as<std::string>(); }

    /// Set the style of the element
    HTMLElement &style(Style style, const std::string &html) {
        auto s = detail::get_style_str(style);
        v["style"].set(s, html);
        return *this;
    }

    /// Get the style of the element
    std::string style(Style style) {
        auto s = detail::get_style_str(style);
        return v["style"][s].as<std::string>();
    }

    /// Set the Html attribute
    HTMLElement &ns_attr(
        const std::string &ns, const std::string &attr, const std::string &val
    ) {
        v.call<void>("setAttributeNS", attr, val);
        return *this;
    }
};

class Document final {
    // NOLINTNEXTLINE
    static inline emscripten::val doc_ = emscripten::val::global("document");

  public:
    explicit Document() = delete;

    /// Set the title of the document
    static void title(const std::string &t) { doc_.set("title", t); }

    static void add_css_link(const std::string &t) {
        auto link = std::string("<link rel='stylesheet' href='") + t + "'/>";
        auto head = doc_.call<emscripten::val>(
            "getElementsByTagName", std::string("head")
        )[0];
        head.call<void>("insertAdjacentHTML", std::string("beforeend"), link);
    }

    /// Get all elements of the specified html className
    static std::vector<HTMLElement> elems_by_class(const std::string &klass) {
        auto elems =
            doc_.call<emscripten::val>("getElementsByClassName", klass);
        auto elems1 = emscripten::vecFromJSArray<emscripten::val>(elems);
        std::vector<HTMLElement> v;
        for (auto elem : elems1) {
            v.emplace_back(elem);
        }
        return v;
    }

    /// Get all elements of the specified html tagName
    static std::vector<HTMLElement> elems_by_tag(const std::string &tag) {
        auto elems = doc_.call<emscripten::val>(
            "getElementsByTagName", emscripten::val(tag)
        );
        auto elems1 = emscripten::vecFromJSArray<emscripten::val>(elems);
        std::vector<HTMLElement> v;
        for (auto elem : elems1) {
            v.emplace_back(elem);
        }
        return v;
    }

    /// Equivalent to JS alert
    template <typename... Ts>
    static void alert(const char *fmt, Ts... ts) {
        auto buf      = detail::format_buf(fmt, ts...);
        std::string a = "alert(" + buf + ");";
        emscripten_run_script(a.c_str());
    }

    /// Equivalent to JS alert
    static void alert(const char *str) {
        std::string a = "alert(" + std::string(str) + ");";
        emscripten_run_script(a.c_str());
    }
};

class Console final {
    // NOLINTNEXTLINE
    const static inline emscripten::val c_ = emscripten::val::global("console");

  public:
    explicit Console() = delete;

    /// Equivalent to console.log
    template <typename... Ts>
    static void log(const char *fmt, Ts... ts) {
        auto buf = detail::format_buf(fmt, ts...);
        c_.call<void>("log", buf);
    }

    /// Equivalent to console.log
    static void log(const char *str) { c_.call<void>("log", std::string(str)); }

    /// Equivalent to console.log
    static void log(emscripten::val v) { c_.call<void>("log", v); }

    /// Equivalent to console.warn
    template <typename... Ts>
    static void warn(const char *fmt, Ts... ts) {
        auto buf = detail::format_buf(fmt, ts...);
        c_.call<void>("warn", buf);
    }

    /// Equivalent to console.warn
    static void warn(const char *str) {
        c_.call<void>("warn", std::string(str));
    }

    /// Equivalent to console.warn
    static void warn(emscripten::val v) { c_.call<void>("warn", v); }

    /// Equivalent to console.error
    template <typename... Ts>
    static void error(const char *fmt, Ts... ts) {
        auto buf = detail::format_buf(fmt, ts...);
        c_.call<void>("error", buf);
    }

    /// Equivalent to console.error
    static void error(const char *str) {
        c_.call<void>("error", std::string(str));
    }

    /// Equivalent to console.error
    static void error(emscripten::val v) { c_.call<void>("error", v); }

    /// Equivalent to console.clear
    static void clear() { c_.call<void>("clear"); }

    /// Equivalent to console.group
    static void group(const char *str) {
        c_.call<void>("group", std::string(str));
    }

    /// Equivalent to console.group
    static void group(emscripten::val v) { c_.call<void>("group", v); }
};

class Canvas : public HTMLElement {
  public:
    Canvas() : HTMLElement(HTMLElementType::Canvas) {}
    Canvas(int w, int h) : HTMLElement(HTMLElementType::Canvas) {
        width(w);
        height(h);
    }
    [[nodiscard]] int width() const { return v["width"].as<int>(); }
    [[nodiscard]] int height() const { return v["height"].as<int>(); }
    void width(int w) { v.set("width", w); }
    void height(int h) { v.set("height", h); }
    auto get_context(const std::string &typ) {
        return v.call<emscripten::val>("getContext", typ);
    }
};

// NOLINTBEGIN
#define ELEMENT(E)                                                             \
    class E : public HTMLElement {                                             \
      public:                                                                  \
        E() : HTMLElement(HTMLElementType::E) {}                               \
    };
// NOLINTEND

ELEMENT(Address)
ELEMENT(Article)
ELEMENT(Aside)
ELEMENT(Footer)
ELEMENT(Header)
ELEMENT(H1)
ELEMENT(H2)
ELEMENT(H3)
ELEMENT(H4)
ELEMENT(H5)
ELEMENT(H6)
ELEMENT(Main)
ELEMENT(Nav)
ELEMENT(Section)
ELEMENT(Blockquote)
ELEMENT(Dd)
ELEMENT(Div)
ELEMENT(Dl)
ELEMENT(Dt)
ELEMENT(Figcaption)
ELEMENT(Figure)
ELEMENT(Hr)
ELEMENT(Li)
ELEMENT(Ol)
ELEMENT(P)
ELEMENT(Pre)
ELEMENT(Ul)
ELEMENT(A)
ELEMENT(Abbr)
ELEMENT(B)
ELEMENT(Bdi)
ELEMENT(Bdo)
ELEMENT(Br)
ELEMENT(Cite)
ELEMENT(Code)
ELEMENT(Data)
ELEMENT(Dfn)
ELEMENT(Em)
ELEMENT(I)
ELEMENT(Kbd)
ELEMENT(Mark)
ELEMENT(Q)
ELEMENT(Rp)
ELEMENT(Rt)
ELEMENT(Ruby)
ELEMENT(S)
ELEMENT(Samp)
ELEMENT(Small)
ELEMENT(Span)
ELEMENT(Strong)
ELEMENT(Sub)
ELEMENT(Sup)
ELEMENT(Time)
ELEMENT(U)
ELEMENT(Var)
ELEMENT(Wbr)
ELEMENT(Area)
ELEMENT(Audio)
ELEMENT(Img)
ELEMENT(Map)
ELEMENT(Track)
ELEMENT(Video)
ELEMENT(Embed)
ELEMENT(Iframe)
ELEMENT(Object)
ELEMENT(Param)
ELEMENT(Picture)
ELEMENT(Portal)
ELEMENT(Source)
ELEMENT(Svg)
ELEMENT(Math)
ELEMENT(Noscript)
ELEMENT(Script)
ELEMENT(Del)
ELEMENT(Ins)
ELEMENT(Caption)
ELEMENT(Col)
ELEMENT(Colgroup)
ELEMENT(Table)
ELEMENT(Tbody)
ELEMENT(Td)
ELEMENT(Tfoot)
ELEMENT(Th)
ELEMENT(Thead)
ELEMENT(Tr)
ELEMENT(Button)
ELEMENT(Datalist)
ELEMENT(Fieldset)
ELEMENT(Form)
ELEMENT(Input)
ELEMENT(Label)
ELEMENT(Legend)
ELEMENT(Meter)
ELEMENT(Optgroup)
ELEMENT(Option)
ELEMENT(Output)
ELEMENT(Progress)
ELEMENT(Select)
ELEMENT(Textarea)
ELEMENT(Details)
ELEMENT(Dialog)
ELEMENT(Menu)
ELEMENT(Summary)
ELEMENT(Slot)
ELEMENT(Template)

} // namespace livid
