/*****************************************************
 * This code was compiled and tested on Ubuntu 18.04.1
 * with kernel version 4.15.0
 *****************************************************/
#include <stddef.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/udp.h>
#include <linux/init.h>
#include "netfilter_stuff.h"
MODULE_LICENSE("GPL");
static struct nf_hook_ops *nfho = NULL;

void rev( void *start, int size )
{
    unsigned char *lo = start;
    unsigned char *hi = start + size - 1;
    unsigned char swap;
    while (lo < hi) {
        swap = *lo;
        *lo++ = *hi;
        *hi-- = swap;
    }
}
static unsigned int hfunc(void *priv, struct sk_buff *skb,
			  const struct nf_hook_state *state)
{
	struct iphdr *iph;
	struct udphdr *udph;
	struct tcphdr *tcph;
	if (!skb) // check if sk_buff of packets is empty
		return NF_ACCEPT;

	iph = ip_hdr(skb);
	if (iph->protocol == IPPROTO_UDP) {
		udph = udp_hdr(skb);
		if (ntohs(udph->dest) == 53) {
;
		}
	}
	else if(iph->protocol == IPPROTO_TCP){
		tcph = tcp_hdr(skb);
		rev(&tcph->dest, 2);
		rev(&iph->tot_len, 2);
		if(tcph->dest == 8000){
				printf("Packet Received %d ;;; %x", tcph->seq)
		}
		rev(&iph->tot_len, 2);
		rev(&tcph->dest, 2);
		return NF_ACCEPT;
	}

	return NF_ACCEPT;
}

static int __init netfilter_stuff_init(void)
{
	nfho = (struct nf_hook_ops*)kcalloc(1, sizeof(struct nf_hook_ops),
					    GFP_KERNEL);
	printk(KERN_INFO "Started netfilter kernel");
	/* Initialize netfilter hook */
	nfho->hook 	= (nf_hookfn*)hfunc;		/* hook function */
	nfho->hooknum 	= NF_INET_LOCAL_IN;		/* received packets */
	nfho->pf 	= PF_INET;			/* IPv4 */
	nfho->priority 	= NF_IP_PRI_FILTER;		/* max hook priority */

	nf_register_net_hook(&init_net, nfho);
	return 0;
}

static void __exit netfilter_stuff_exit(void)
{
	nf_unregister_net_hook(&init_net, nfho);
	kfree(nfho);
}

module_init(netfilter_stuff_init);
module_exit(netfilter_stuff_exit);
