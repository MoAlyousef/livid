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

#ifndef __LIVID_HPP__
#define __LIVID_HPP__

#include <cstdio>
#include <cstring>
#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <functional>
#include <map>
#include <string>
#include <vector>

/// [INTERNAL]
EMSCRIPTEN_BINDINGS(MyBindings)
{
    emscripten::class_<std::function<void(emscripten::val)>>("ListenerCallback")
        .constructor<>()
        .function("_internal_func_", &std::function<void(emscripten::val)>::operator());
};

namespace livid {

/// List of all available Html elements
enum class WidgetType {
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
enum class Event {
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
// clang-format off
/// [INTERNAL]
constexpr const char *get_element_str(WidgetType typ) {
    switch (typ) {
        case WidgetType::Address: return "address";
        case WidgetType::Article: return "article";
        case WidgetType::Aside: return "aside";
        case WidgetType::Footer: return "footer";
        case WidgetType::Header: return "header";
        case WidgetType::H1: return "h1";
        case WidgetType::H2: return "h2";
        case WidgetType::H3: return "h3";
        case WidgetType::H4: return "h4";
        case WidgetType::H5: return "h5";
        case WidgetType::H6: return "h6";
        case WidgetType::Main: return "main";
        case WidgetType::Nav: return "nav";
        case WidgetType::Section: return "section";
        case WidgetType::Blockquote: return "blockquote";
        case WidgetType::Dd: return "dd";
        case WidgetType::Div: return "div";
        case WidgetType::Dl: return "dl";
        case WidgetType::Dt: return "dt";
        case WidgetType::Figcaption: return "figcaption";
        case WidgetType::Figure: return "figure";
        case WidgetType::Hr: return "hr";
        case WidgetType::Li: return "li";
        case WidgetType::Ol: return "ol";
        case WidgetType::P: return "p";
        case WidgetType::Pre: return "pre";
        case WidgetType::Ul: return "ul";
        case WidgetType::A: return "a";
        case WidgetType::Abbr: return "abbr";
        case WidgetType::B: return "b";
        case WidgetType::Bdi: return "bdi";
        case WidgetType::Bdo: return "bdo";
        case WidgetType::Br: return "br";
        case WidgetType::Cite: return "cite";
        case WidgetType::Code: return "code";
        case WidgetType::Data: return "data";
        case WidgetType::Dfn: return "dfn";
        case WidgetType::Em: return "em";
        case WidgetType::I: return "i";
        case WidgetType::Kbd: return "kbd";
        case WidgetType::Mark: return "mark";
        case WidgetType::Q: return "q";
        case WidgetType::Rp: return "rp";
        case WidgetType::Rt: return "rt";
        case WidgetType::Ruby: return "ruby";
        case WidgetType::S: return "s";
        case WidgetType::Samp: return "samp";
        case WidgetType::Small: return "small";
        case WidgetType::Span: return "span";
        case WidgetType::Strong: return "strong";
        case WidgetType::Sub: return "sub";
        case WidgetType::Sup: return "sup";
        case WidgetType::Time: return "time";
        case WidgetType::U: return "u";
        case WidgetType::Var: return "var";
        case WidgetType::Wbr: return "wbr";
        case WidgetType::Area: return "area";
        case WidgetType::Audio: return "audio";
        case WidgetType::Img: return "img";
        case WidgetType::Map: return "map";
        case WidgetType::Track: return "track";
        case WidgetType::Video: return "video";
        case WidgetType::Embed: return "embed";
        case WidgetType::Iframe: return "iframe";
        case WidgetType::Object: return "object";
        case WidgetType::Param: return "param";
        case WidgetType::Picture: return "picture";
        case WidgetType::Portal: return "portal";
        case WidgetType::Source: return "source";
        case WidgetType::Svg: return "svg";
        case WidgetType::Math: return "math";
        case WidgetType::Canvas: return "canvas";
        case WidgetType::Noscript: return "noscript";
        case WidgetType::Script: return "script";
        case WidgetType::Del: return "del";
        case WidgetType::Ins: return "ins";
        case WidgetType::Caption: return "caption";
        case WidgetType::Col: return "col";
        case WidgetType::Colgroup: return "colgroup";
        case WidgetType::Table: return "table";
        case WidgetType::Tbody: return "tbody";
        case WidgetType::Td: return "td";
        case WidgetType::Tfoot: return "tfoot";
        case WidgetType::Th: return "th";
        case WidgetType::Thead: return "thead";
        case WidgetType::Tr: return "tr";
        case WidgetType::Button: return "button";
        case WidgetType::Datalist: return "datalist";
        case WidgetType::Fieldset: return "fieldset";
        case WidgetType::Form: return "form";
        case WidgetType::Input: return "input";
        case WidgetType::Label: return "label";
        case WidgetType::Legend: return "legend";
        case WidgetType::Meter: return "meter";
        case WidgetType::Optgroup: return "optgroup";
        case WidgetType::Option: return "option";
        case WidgetType::Output: return "output";
        case WidgetType::Progress: return "progress";
        case WidgetType::Select: return "select";
        case WidgetType::Textarea: return "textarea";
        case WidgetType::Details: return "details";
        case WidgetType::Dialog: return "dialog";
        case WidgetType::Menu: return "menu";
        case WidgetType::Summary: return "summary";
        case WidgetType::Slot: return "slot";
        case WidgetType::Template: return "template";
        default: return "div";
    }
}

constexpr const char *get_event_str(Event ev) {
    switch (ev) {
        case Event::Abort: return "abort";
        case Event::Afterprint: return "afterprint";
        case Event::Animationend: return "animationend";
        case Event::Animationiteration: return "animationiteration";
        case Event::Animationstart: return "animationstart";
        case Event::Beforeprint: return "beforeprint";
        case Event::Beforeunload: return "beforeunload";
        case Event::Blur: return "blur";
        case Event::Canplay: return "canplay";
        case Event::Canplaythrough: return "canplaythrough";
        case Event::Change: return "change";
        case Event::Click: return "click";
        case Event::Contextmenu: return "contextmenu";
        case Event::Copy: return "copy";
        case Event::Cut: return "cut";
        case Event::Dblclick: return "dblclick";
        case Event::Drag: return "drag";
        case Event::Dragend: return "dragend";
        case Event::Dragenter: return "dragenter";
        case Event::Dragleave: return "dragleave";
        case Event::Dragover: return "dragover";
        case Event::Dragstart: return "dragstart";
        case Event::Drop: return "drop";
        case Event::Durationchange: return "durationchange";
        case Event::Ended: return "ended";
        case Event::Error: return "error";
        case Event::Focus: return "focus";
        case Event::Focusin: return "focusin";
        case Event::Focusout: return "focusout";
        case Event::Fullscreenchange: return "fullscreenchange";
        case Event::Fullscreenerror: return "fullscreenerror";
        case Event::Hashchange: return "hashchange";
        case Event::Input: return "input";
        case Event::Invalid: return "invalid";
        case Event::Keydown: return "keydown";
        case Event::Keypress: return "keypress";
        case Event::Keyup: return "keyup";
        case Event::Load: return "load";
        case Event::Loadeddata: return "loadeddata";
        case Event::Loadedmetadata: return "loadedmetadata";
        case Event::Loadstart: return "loadstart";
        case Event::Message: return "message";
        case Event::Mousedown: return "mousedown";
        case Event::Mouseenter: return "mouseenter";
        case Event::Mouseleave: return "mouseleave";
        case Event::Mousemove: return "mousemove";
        case Event::Mouseover: return "mouseover";
        case Event::Mouseout: return "mouseout";
        case Event::Mouseup: return "mouseup";
        case Event::Mousewheel: return "mousewheel";
        case Event::Offline: return "offline";
        case Event::Online: return "online";
        case Event::Open: return "open";
        case Event::Pagehide: return "pagehide";
        case Event::Pageshow: return "pageshow";
        case Event::Paste: return "paste";
        case Event::Pause: return "pause";
        case Event::Play: return "play";
        case Event::Playing: return "playing";
        case Event::Popstate: return "popstate";
        case Event::Progress: return "progress";
        case Event::Ratechange: return "ratechange";
        case Event::Resize: return "resize";
        case Event::Reset: return "reset";
        case Event::Scroll: return "scroll";
        case Event::Search: return "search";
        case Event::Seeked: return "seeked";
        case Event::Seeking: return "seeking";
        case Event::Select: return "select";
        case Event::Show: return "show";
        case Event::Stalled: return "stalled";
        case Event::Storage: return "storage";
        case Event::Submit: return "submit";
        case Event::Suspend: return "suspend";
        case Event::Timeupdate: return "timeupdate";
        case Event::Toggle: return "toggle";
        case Event::Touchcancel: return "touchcancel";
        case Event::Touchend: return "touchend";
        case Event::Touchmove: return "touchmove";
        case Event::Touchstart: return "touchstart";
        case Event::Transitionend: return "transitionend";
        case Event::Unload: return "unload";
        case Event::Volumechange: return "volumechange";
        case Event::Waiting: return "waiting";
        case Event::Wheel: return "wheel";
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

/// Holds the implementation of all widgets, not specific to WidgetType
class WidgetBase {
  protected:
    emscripten::val v = emscripten::val::null();

    WidgetBase() {}

  public:
    WidgetBase(emscripten::val val): v(val) {}

    WidgetBase(const WidgetBase &other) = default;

    WidgetBase(WidgetBase &&other) = default;

    WidgetBase &operator=(const WidgetBase &other) {
        *this = other;
        return *this;
    }

    /// Construct a WidgetBase from an html id
    static WidgetBase from_id(const std::string &id) { 
        auto doc = emscripten::val::global("document");
        auto elem = doc.call<emscripten::val>("getElementById", emscripten::val(id.c_str()));
        return WidgetBase(elem);
    }

    /// Delete a widget
    static void delete_widget(WidgetBase &&elem) {
        elem.outer_html("");
    }

    /// Get the Html id
    std::string id() const { return v["id"].as<std::string>(); }

    /// Set the Html id
    WidgetBase &id(const std::string &val) {
        v.set("id", val);
        return *this;
    }

    /// Set the Html attribute
    WidgetBase &attr(const std::string &attr, const std::string &val) {
        v.call<void>("setAttribute", attr, val);
        return *this;
    }

    /// Get the Html attribute
    std::string attr(const std::string &attr) {
        return v.call<emscripten::val>("getAttribute", attr).as<std::string>();
    }

    /// Set the Html class
    WidgetBase &klass(const std::string &val) {
        v.set("className", val);
        return *this;
    }

    /// Get the Html class
    std::string klass() {
        return v["className"].as<std::string>();
    }

    /// Append a child
    WidgetBase &append(const WidgetBase &w) {
        v.call<void>("appendChild", w.v);
        return *this;
    }

    /// Remove a child
    WidgetBase &remove(const WidgetBase &w) {
        v.call<void>("removeChild", w.v);
        return *this;
    }

    /// Add an event listener
    WidgetBase &handle(Event event, std::function<void(emscripten::val)> &&func) {
        emscripten::val cb = emscripten::val(func)["_internal_func_"].call<emscripten::val>("bind", emscripten::val(func));
        v.call<void>("addEventListener", std::string(detail::get_event_str(event)), cb);
        return *this;
    }

    /// Set the text content
    WidgetBase &text(const std::string &html) {
        v.set("textContent", html);
        return *this;
    }

    /// Get the text content
    std::string text() {
        return v["textContent"].as<std::string>();
    }

    /// Set the outer html
    WidgetBase &outer_html(const std::string &html) {
        v.set("outerHTML", html);
        return *this;
    }

    /// Get the outer html
    std::string outer_html() {
        return v["outerHTML"].as<std::string>();
    }

    /// Set the inner html
    WidgetBase &inner_html(const std::string &html) {
        v.set("innerHTML", html);
        return *this;
    }

    /// Get the inner html
    std::string inner_html() {
        return v["innerHTML"].as<std::string>();
    }

    /// Set the href value
    WidgetBase &href(const std::string &html) {
        v.set("href", html);
        return *this;
    }

    /// Get the href value
    std::string href() {
        return v["href"].as<std::string>();
    }

    /// Set the style of the widget
    WidgetBase &style(Style style, const std::string &html) {
        auto s = detail::get_style_str(style);
        v["style"].set(s, html);
        return *this;
    }

    /// Get the style of the widget
    std::string style(Style style) {
        auto s = detail::get_style_str(style);
        return v["style"][s].as<std::string>();
    }
};

template <WidgetType widget_type>
class Widget : public WidgetBase {
  public:
    Widget() : WidgetBase() {
        const char *element = detail::get_element_str(widget_type);
        auto doc = emscripten::val::global("document");
        v = doc.call<emscripten::val>("createElement", emscripten::val(element));
        doc.call<emscripten::val>("getElementsByTagName", emscripten::val("body"))[0].call<void>("appendChild", v);
    }

    explicit Widget(const std::string &id) : WidgetBase() {
        const char *element = detail::get_element_str(widget_type);
        auto doc = emscripten::val::global("document");
        v = doc.call<emscripten::val>("createElement", emscripten::val(element));
        doc.call<emscripten::val>("getElementsByTagName", emscripten::val("body"))[0].call<void>("appendChild", v);
        v.set("id", id);
    }

    Widget(const Widget &other) = default;

    Widget(Widget &&other) = default;

    Widget &operator=(const Widget &other) {
        *this = other;
        return *this;
    }
};

template <>
class Widget<WidgetType::Svg> : public WidgetBase {
  public:
    Widget() : WidgetBase() {
        auto doc = emscripten::val::global("document");
        v = doc.call<emscripten::val>("createElementNS", emscripten::val("http://www.w3.org/2000/svg"), emscripten::val("svg"));
        doc.call<emscripten::val>("getElementsByTagName", emscripten::val("body"))[0].call<void>("appendChild", v);
    }

    explicit Widget(const std::string &id) : WidgetBase() {
        auto doc = emscripten::val::global("document");
        v = doc.call<emscripten::val>("createElementNS", emscripten::val("http://www.w3.org/2000/svg"), emscripten::val("svg"));
        v.set("id", id);
        doc.call<emscripten::val>("getElementsByTagName", emscripten::val("body"))[0].call<void>("appendChild", v);
    }

    Widget(const Widget &other) = default;
    Widget(Widget &&other) = default;
    Widget &operator=(const Widget &other) {
        *this = other;
        return *this;
    }
};

/// A namespaced widget, like svg
class NSWidget : public WidgetBase {
  public:
    explicit NSWidget(const std::string &ns, const std::string &tag, const std::string &id)
        : WidgetBase() {
        auto doc = emscripten::val::global("document");
        v = doc.call<emscripten::val>("createElementNS", ns, tag);
        v.set("id", id);
        doc.call<emscripten::val>("getElementsByTagName", emscripten::val("body"))[0].call<void>("appendChild", v);
    }

    explicit NSWidget(const std::string &ns, const std::string &tag) : WidgetBase() {
        auto doc = emscripten::val::global("document");
        v = doc.call<emscripten::val>("createElementNS", ns, tag);
        doc.call<emscripten::val>("getElementsByTagName", emscripten::val("body"))[0].call<void>("appendChild", v);
    }

    NSWidget(const NSWidget &other) = default;

    NSWidget(NSWidget &&other) = default;

    NSWidget &operator=(const NSWidget &other) {
        *this = other;
        return *this;
    }

    /// Set the Html attribute
    NSWidget &ns_attr(const std::string &ns, const std::string &attr, const std::string &val) {
        v.call<void>("setAttributeNS", attr, val);
        return *this;
    }
};

class Document final {
    static inline emscripten::val doc_ = emscripten::val::global("document");
  public:
    explicit Document() = delete;

    /// Set the title of the document
    static void title(const std::string &t) {
        doc_.set("title", t);
    }

    /// Get all elements of the specified html className
    static std::vector<WidgetBase> elems_by_class(const std::string &klass) {
        auto elems = doc_.call<emscripten::val>("getElementsByClassName", klass);
        auto elems1 = emscripten::vecFromJSArray<emscripten::val>(elems);
        std::vector<WidgetBase> v;
        for (auto elem : elems1) {
            v.push_back(WidgetBase(elem));
        }
        return v;
    }

    /// Get all elements of the specified html tagName
    static std::vector<WidgetBase> elems_by_tag(const std::string &tag) {
        auto elems = doc_.call<emscripten::val>("getElementsByTagName", tag);
        auto elems1 = emscripten::vecFromJSArray<emscripten::val>(elems);
        std::vector<WidgetBase> v;
        for (auto elem : elems1) {
            v.push_back(WidgetBase(elem));
        }
        return v;
    }

    /// Equivalent to JS alert
    template <typename... Ts>
    static void alert(const char *fmt, Ts... ts) {
        auto sz = snprintf(nullptr, 0, fmt, ts...);
        auto buf = (char *)malloc(sz + 1);
        auto ret = snprintf(buf, sz + 1, fmt, ts...);
        std::string a = "alert(" + std::string(buf) + ");";
        emscripten_run_script(a.c_str());
        free(buf);
    }

    /// Equivalent to JS alert
    static void alert(const char *str) {
        std::string a = "alert(" + std::string(str) + ");";
        emscripten_run_script(a.c_str());
    }
};

class Console final {
    static inline emscripten::val console_ = emscripten::val::global("console");
  public:
    explicit Console() = delete;

    /// Equivalent to console.log
    template <typename... Ts>
    static void log(const char *fmt, Ts... ts) {
        auto sz = snprintf(nullptr, 0, fmt, ts...);
        auto buf = (char *)malloc(sz + 1);
        auto ret = snprintf(buf, sz + 1, fmt, ts...);
        console_.call<void>("log", std::string(buf));
        free(buf);
    }

    /// Equivalent to console.log
    static void log(const char *str) {
        console_.call<void>("log", std::string(str));
    }

    /// Equivalent to console.log
    static void log(emscripten::val v) {
        console_.call<void>("log", v);
    }

    /// Equivalent to console.warn
    template <typename... Ts>
    static void warn(const char *fmt, Ts... ts) {
        auto sz = snprintf(nullptr, 0, fmt, ts...);
        auto buf = (char *)malloc(sz + 1);
        auto ret = snprintf(buf, sz + 1, fmt, ts...);
        console_.call<void>("warn", std::string(buf));
        free(buf);
    }

    /// Equivalent to console.warn
    static void warn(const char *str) {
        console_.call<void>("warn", std::string(str));
    }

    /// Equivalent to console.warn
    static void warn(emscripten::val v) {
        console_.call<void>("warn", v);
    }

    /// Equivalent to console.error
    template <typename... Ts>
    static void error(const char *fmt, Ts... ts) {
        auto sz = snprintf(nullptr, 0, fmt, ts...);
        auto buf = (char *)malloc(sz + 1);
        auto ret = snprintf(buf, sz + 1, fmt, ts...);
        console_.call<void>("error", std::string(buf));
        free(buf);
    }

    /// Equivalent to console.error
    static void error(const char *str) {
        console_.call<void>("error", std::string(str));
    }

    /// Equivalent to console.error
    static void error(emscripten::val v) {
        console_.call<void>("error", v);
    }

    /// Equivalent to console.clear
    static void clear() {
        console_.call<void>("clear");
    }

    /// Equivalent to console.group
    static void group(const char *str) {
        console_.call<void>("group", std::string(str));
    }

    /// Equivalent to console.group
    static void group(emscripten::val v) {
        console_.call<void>("group", v);
    }
};

} // namespace livid

#endif
