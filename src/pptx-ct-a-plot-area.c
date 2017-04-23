#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-plot-area.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-layout.h>
#include <private/pptx-ct-a-area-chart.h>
#include <private/pptx-ct-a-area-3dchart.h>
#include <private/pptx-ct-a-line-chart.h>
#include <private/pptx-ct-a-line-3dchart.h>
#include <private/pptx-ct-a-stock-chart.h>
#include <private/pptx-ct-a-radar-chart.h>
#include <private/pptx-ct-a-scatter-chart.h>
#include <private/pptx-ct-a-pie-chart.h>
#include <private/pptx-ct-a-pie-3dchart.h>
#include <private/pptx-ct-a-doughnut-chart.h>
#include <private/pptx-ct-a-bar-chart.h>
#include <private/pptx-ct-a-bar-3dchart.h>
#include <private/pptx-ct-a-of-pie-chart.h>
#include <private/pptx-ct-a-surface-chart.h>
#include <private/pptx-ct-a-surface-3dchart.h>
#include <private/pptx-ct-a-bubble-chart.h>
#include <private/pptx-ct-a-val-ax.h>
#include <private/pptx-ct-a-cat-ax.h>
#include <private/pptx-ct-a-date-ax.h>
#include <private/pptx-ct-a-ser-ax.h>
#include <private/pptx-ct-a-dtable.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_plot_area_s {
    pptx_ct_a_layout *layout;
    pptx_ct_a_area_chart **area_chart;
    pptx_ct_a_area_3dchart **area_3dchart;
    pptx_ct_a_line_chart **line_chart;
    pptx_ct_a_line_3dchart **line_3dchart;
    pptx_ct_a_stock_chart **stock_chart;
    pptx_ct_a_radar_chart **radar_chart;
    pptx_ct_a_scatter_chart **scatter_chart;
    pptx_ct_a_pie_chart **pie_chart;
    pptx_ct_a_pie_3dchart **pie_3dchart;
    pptx_ct_a_doughnut_chart **doughnut_chart;
    pptx_ct_a_bar_chart **bar_chart;
    pptx_ct_a_bar_3dchart **bar_3dchart;
    pptx_ct_a_of_pie_chart **of_pie_chart;
    pptx_ct_a_surface_chart **surface_chart;
    pptx_ct_a_surface_3dchart **surface_3dchart;
    pptx_ct_a_bubble_chart **bubble_chart;
    pptx_ct_a_val_ax **val_ax;
    pptx_ct_a_cat_ax **cat_ax;
    pptx_ct_a_date_ax **date_ax;
    pptx_ct_a_ser_ax **ser_ax;
    pptx_ct_a_dtable *d_table;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_plot_area;

pptx_ct_a_plot_area *
pptx_ct_a_plot_area_new(xmlNode *node)
{
    pptx_ct_a_plot_area *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:layout");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->layout = NULL;
        } else {
            obj->layout = pptx_ct_a_layout_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->layout = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:areaChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->area_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->area_chart);
            if (obj->area_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->area_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_area_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->area_chart);
                    obj->area_chart = NULL;
                } else {
                    obj->area_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->area_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->area_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:area3DChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->area_3dchart = malloc((nodes->nodeNr + 1) * sizeof *obj->area_3dchart);
            if (obj->area_3dchart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->area_3dchart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_area_3dchart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->area_3dchart);
                    obj->area_3dchart = NULL;
                } else {
                    obj->area_3dchart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->area_3dchart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->area_3dchart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lineChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->line_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->line_chart);
            if (obj->line_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->line_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_line_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->line_chart);
                    obj->line_chart = NULL;
                } else {
                    obj->line_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->line_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:line3DChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->line_3dchart = malloc((nodes->nodeNr + 1) * sizeof *obj->line_3dchart);
            if (obj->line_3dchart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->line_3dchart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_line_3dchart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->line_3dchart);
                    obj->line_3dchart = NULL;
                } else {
                    obj->line_3dchart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->line_3dchart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_3dchart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:stockChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->stock_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->stock_chart);
            if (obj->stock_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->stock_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_stock_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->stock_chart);
                    obj->stock_chart = NULL;
                } else {
                    obj->stock_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->stock_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->stock_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:radarChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->radar_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->radar_chart);
            if (obj->radar_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->radar_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_radar_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->radar_chart);
                    obj->radar_chart = NULL;
                } else {
                    obj->radar_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->radar_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->radar_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:scatterChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->scatter_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->scatter_chart);
            if (obj->scatter_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->scatter_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_scatter_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->scatter_chart);
                    obj->scatter_chart = NULL;
                } else {
                    obj->scatter_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->scatter_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->scatter_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pieChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->pie_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->pie_chart);
            if (obj->pie_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->pie_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_pie_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->pie_chart);
                    obj->pie_chart = NULL;
                } else {
                    obj->pie_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->pie_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pie_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pie3DChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->pie_3dchart = malloc((nodes->nodeNr + 1) * sizeof *obj->pie_3dchart);
            if (obj->pie_3dchart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->pie_3dchart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_pie_3dchart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->pie_3dchart);
                    obj->pie_3dchart = NULL;
                } else {
                    obj->pie_3dchart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->pie_3dchart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pie_3dchart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:doughnutChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->doughnut_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->doughnut_chart);
            if (obj->doughnut_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->doughnut_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_doughnut_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->doughnut_chart);
                    obj->doughnut_chart = NULL;
                } else {
                    obj->doughnut_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->doughnut_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->doughnut_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:barChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bar_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->bar_chart);
            if (obj->bar_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bar_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_bar_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->bar_chart);
                    obj->bar_chart = NULL;
                } else {
                    obj->bar_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bar_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bar_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bar3DChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bar_3dchart = malloc((nodes->nodeNr + 1) * sizeof *obj->bar_3dchart);
            if (obj->bar_3dchart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bar_3dchart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_bar_3dchart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->bar_3dchart);
                    obj->bar_3dchart = NULL;
                } else {
                    obj->bar_3dchart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bar_3dchart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bar_3dchart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ofPieChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->of_pie_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->of_pie_chart);
            if (obj->of_pie_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->of_pie_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_of_pie_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->of_pie_chart);
                    obj->of_pie_chart = NULL;
                } else {
                    obj->of_pie_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->of_pie_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->of_pie_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:surfaceChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->surface_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->surface_chart);
            if (obj->surface_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->surface_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_surface_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->surface_chart);
                    obj->surface_chart = NULL;
                } else {
                    obj->surface_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->surface_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->surface_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:surface3DChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->surface_3dchart = malloc((nodes->nodeNr + 1) * sizeof *obj->surface_3dchart);
            if (obj->surface_3dchart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->surface_3dchart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_surface_3dchart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->surface_3dchart);
                    obj->surface_3dchart = NULL;
                } else {
                    obj->surface_3dchart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->surface_3dchart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->surface_3dchart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bubbleChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bubble_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->bubble_chart);
            if (obj->bubble_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bubble_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_bubble_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->bubble_chart);
                    obj->bubble_chart = NULL;
                } else {
                    obj->bubble_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bubble_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bubble_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:valAx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->val_ax = malloc((nodes->nodeNr + 1) * sizeof *obj->val_ax);
            if (obj->val_ax != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->val_ax;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_val_ax_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->val_ax);
                    obj->val_ax = NULL;
                } else {
                    obj->val_ax[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->val_ax = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->val_ax = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:catAx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cat_ax = malloc((nodes->nodeNr + 1) * sizeof *obj->cat_ax);
            if (obj->cat_ax != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cat_ax;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_cat_ax_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cat_ax);
                    obj->cat_ax = NULL;
                } else {
                    obj->cat_ax[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cat_ax = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cat_ax = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dateAx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->date_ax = malloc((nodes->nodeNr + 1) * sizeof *obj->date_ax);
            if (obj->date_ax != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->date_ax;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_date_ax_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->date_ax);
                    obj->date_ax = NULL;
                } else {
                    obj->date_ax[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->date_ax = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->date_ax = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:serAx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ser_ax = malloc((nodes->nodeNr + 1) * sizeof *obj->ser_ax);
            if (obj->ser_ax != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ser_ax;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_ser_ax_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ser_ax);
                    obj->ser_ax = NULL;
                } else {
                    obj->ser_ax[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ser_ax = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ser_ax = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dTable");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->d_table = NULL;
        } else {
            obj->d_table = pptx_ct_a_dtable_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->d_table = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_layout *
pptx_ct_a_plot_area_get_layout(const pptx_ct_a_plot_area *const obj)
{
    return obj->layout;
}

pptx_ct_a_area_chart **
pptx_ct_a_plot_area_get_area_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->area_chart;
}

pptx_ct_a_area_3dchart **
pptx_ct_a_plot_area_get_area_3dchart(const pptx_ct_a_plot_area *const obj)
{
    return obj->area_3dchart;
}

pptx_ct_a_line_chart **
pptx_ct_a_plot_area_get_line_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->line_chart;
}

pptx_ct_a_line_3dchart **
pptx_ct_a_plot_area_get_line_3dchart(const pptx_ct_a_plot_area *const obj)
{
    return obj->line_3dchart;
}

pptx_ct_a_stock_chart **
pptx_ct_a_plot_area_get_stock_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->stock_chart;
}

pptx_ct_a_radar_chart **
pptx_ct_a_plot_area_get_radar_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->radar_chart;
}

pptx_ct_a_scatter_chart **
pptx_ct_a_plot_area_get_scatter_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->scatter_chart;
}

pptx_ct_a_pie_chart **
pptx_ct_a_plot_area_get_pie_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->pie_chart;
}

pptx_ct_a_pie_3dchart **
pptx_ct_a_plot_area_get_pie_3dchart(const pptx_ct_a_plot_area *const obj)
{
    return obj->pie_3dchart;
}

pptx_ct_a_doughnut_chart **
pptx_ct_a_plot_area_get_doughnut_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->doughnut_chart;
}

pptx_ct_a_bar_chart **
pptx_ct_a_plot_area_get_bar_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->bar_chart;
}

pptx_ct_a_bar_3dchart **
pptx_ct_a_plot_area_get_bar_3dchart(const pptx_ct_a_plot_area *const obj)
{
    return obj->bar_3dchart;
}

pptx_ct_a_of_pie_chart **
pptx_ct_a_plot_area_get_of_pie_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->of_pie_chart;
}

pptx_ct_a_surface_chart **
pptx_ct_a_plot_area_get_surface_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->surface_chart;
}

pptx_ct_a_surface_3dchart **
pptx_ct_a_plot_area_get_surface_3dchart(const pptx_ct_a_plot_area *const obj)
{
    return obj->surface_3dchart;
}

pptx_ct_a_bubble_chart **
pptx_ct_a_plot_area_get_bubble_chart(const pptx_ct_a_plot_area *const obj)
{
    return obj->bubble_chart;
}

pptx_ct_a_val_ax **
pptx_ct_a_plot_area_get_val_ax(const pptx_ct_a_plot_area *const obj)
{
    return obj->val_ax;
}

pptx_ct_a_cat_ax **
pptx_ct_a_plot_area_get_cat_ax(const pptx_ct_a_plot_area *const obj)
{
    return obj->cat_ax;
}

pptx_ct_a_date_ax **
pptx_ct_a_plot_area_get_date_ax(const pptx_ct_a_plot_area *const obj)
{
    return obj->date_ax;
}

pptx_ct_a_ser_ax **
pptx_ct_a_plot_area_get_ser_ax(const pptx_ct_a_plot_area *const obj)
{
    return obj->ser_ax;
}

pptx_ct_a_dtable *
pptx_ct_a_plot_area_get_d_table(const pptx_ct_a_plot_area *const obj)
{
    return obj->d_table;
}

pptx_ct_a_shape_properties *
pptx_ct_a_plot_area_get_sp_pr(const pptx_ct_a_plot_area *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_extension_list *
pptx_ct_a_plot_area_get_ext_lst(const pptx_ct_a_plot_area *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_plot_area_get_index(pptx_ct_a_plot_area *obj)
{
    return obj->index;
}

void
pptx_ct_a_plot_area_free(pptx_ct_a_plot_area *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_layout_free(obj->layout);
    if (obj->area_chart != NULL) {
        for (int i = 0; obj->area_chart[i] != NULL; ++i) {
            pptx_ct_a_area_chart_free(obj->area_chart[i]);
        }
        free(obj->area_chart);
    }

    if (obj->area_3dchart != NULL) {
        for (int i = 0; obj->area_3dchart[i] != NULL; ++i) {
            pptx_ct_a_area_3dchart_free(obj->area_3dchart[i]);
        }
        free(obj->area_3dchart);
    }

    if (obj->line_chart != NULL) {
        for (int i = 0; obj->line_chart[i] != NULL; ++i) {
            pptx_ct_a_line_chart_free(obj->line_chart[i]);
        }
        free(obj->line_chart);
    }

    if (obj->line_3dchart != NULL) {
        for (int i = 0; obj->line_3dchart[i] != NULL; ++i) {
            pptx_ct_a_line_3dchart_free(obj->line_3dchart[i]);
        }
        free(obj->line_3dchart);
    }

    if (obj->stock_chart != NULL) {
        for (int i = 0; obj->stock_chart[i] != NULL; ++i) {
            pptx_ct_a_stock_chart_free(obj->stock_chart[i]);
        }
        free(obj->stock_chart);
    }

    if (obj->radar_chart != NULL) {
        for (int i = 0; obj->radar_chart[i] != NULL; ++i) {
            pptx_ct_a_radar_chart_free(obj->radar_chart[i]);
        }
        free(obj->radar_chart);
    }

    if (obj->scatter_chart != NULL) {
        for (int i = 0; obj->scatter_chart[i] != NULL; ++i) {
            pptx_ct_a_scatter_chart_free(obj->scatter_chart[i]);
        }
        free(obj->scatter_chart);
    }

    if (obj->pie_chart != NULL) {
        for (int i = 0; obj->pie_chart[i] != NULL; ++i) {
            pptx_ct_a_pie_chart_free(obj->pie_chart[i]);
        }
        free(obj->pie_chart);
    }

    if (obj->pie_3dchart != NULL) {
        for (int i = 0; obj->pie_3dchart[i] != NULL; ++i) {
            pptx_ct_a_pie_3dchart_free(obj->pie_3dchart[i]);
        }
        free(obj->pie_3dchart);
    }

    if (obj->doughnut_chart != NULL) {
        for (int i = 0; obj->doughnut_chart[i] != NULL; ++i) {
            pptx_ct_a_doughnut_chart_free(obj->doughnut_chart[i]);
        }
        free(obj->doughnut_chart);
    }

    if (obj->bar_chart != NULL) {
        for (int i = 0; obj->bar_chart[i] != NULL; ++i) {
            pptx_ct_a_bar_chart_free(obj->bar_chart[i]);
        }
        free(obj->bar_chart);
    }

    if (obj->bar_3dchart != NULL) {
        for (int i = 0; obj->bar_3dchart[i] != NULL; ++i) {
            pptx_ct_a_bar_3dchart_free(obj->bar_3dchart[i]);
        }
        free(obj->bar_3dchart);
    }

    if (obj->of_pie_chart != NULL) {
        for (int i = 0; obj->of_pie_chart[i] != NULL; ++i) {
            pptx_ct_a_of_pie_chart_free(obj->of_pie_chart[i]);
        }
        free(obj->of_pie_chart);
    }

    if (obj->surface_chart != NULL) {
        for (int i = 0; obj->surface_chart[i] != NULL; ++i) {
            pptx_ct_a_surface_chart_free(obj->surface_chart[i]);
        }
        free(obj->surface_chart);
    }

    if (obj->surface_3dchart != NULL) {
        for (int i = 0; obj->surface_3dchart[i] != NULL; ++i) {
            pptx_ct_a_surface_3dchart_free(obj->surface_3dchart[i]);
        }
        free(obj->surface_3dchart);
    }

    if (obj->bubble_chart != NULL) {
        for (int i = 0; obj->bubble_chart[i] != NULL; ++i) {
            pptx_ct_a_bubble_chart_free(obj->bubble_chart[i]);
        }
        free(obj->bubble_chart);
    }

    if (obj->val_ax != NULL) {
        for (int i = 0; obj->val_ax[i] != NULL; ++i) {
            pptx_ct_a_val_ax_free(obj->val_ax[i]);
        }
        free(obj->val_ax);
    }

    if (obj->cat_ax != NULL) {
        for (int i = 0; obj->cat_ax[i] != NULL; ++i) {
            pptx_ct_a_cat_ax_free(obj->cat_ax[i]);
        }
        free(obj->cat_ax);
    }

    if (obj->date_ax != NULL) {
        for (int i = 0; obj->date_ax[i] != NULL; ++i) {
            pptx_ct_a_date_ax_free(obj->date_ax[i]);
        }
        free(obj->date_ax);
    }

    if (obj->ser_ax != NULL) {
        for (int i = 0; obj->ser_ax[i] != NULL; ++i) {
            pptx_ct_a_ser_ax_free(obj->ser_ax[i]);
        }
        free(obj->ser_ax);
    }

    pptx_ct_a_dtable_free(obj->d_table);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}